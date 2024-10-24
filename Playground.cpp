#include "Playground.h"
#include "addProjectileAction.h"
#include "Transition.hpp"
#include "DoNothing.h"
#include "Condition_EnemyInLane.h"

namespace
{
static Playground* sInstance = nullptr;
}

void Playground::checkCollision()
{
	int countProjectile = 0;
	for (auto& p : mProjectiles)
	{
		int countEnemy = 0;
		for (auto& e : mEnemy)
		{
			if (p->getPosition().y == e->getPosition().y)
			{
				if (p->getPosition().x + 5.f >= e->getPosition().x - 10.f && p->getPosition().x + 5.f <= e->getPosition().x + 10)
				{
					mProjectiles.erase(mProjectiles.begin() + countProjectile);
					countProjectile--;
					mEnemy.erase(mEnemy.begin() + countEnemy);
					countEnemy--;
				}
			}
			countEnemy++;

		}
		countProjectile++;
	}
}

Playground* Playground::instantiate()
{
	if (!sInstance)
	{
		sInstance = new Playground();
		return sInstance;
	}
	return nullptr;
}

Playground::Playground()
{
	Behaviour* plantBehaviour = new Behaviour();

	plantBehaviour->AddAction(Context::State::idle, new DoNothing);
	Transition* ptr = new Transition;
	ptr->addCondition(new Condition_EnemyInLane);
	ptr->setTargetState(Context::State::shoot);
	plantBehaviour->AddTransition(Context::State::idle, ptr);
	plantBehaviour->AddAction(Context::State::shoot, new AddProjectileAction);

	// action:;
	// AddProjectileAction
	// plantBehaviour->addaction(context::state::idle, new addprojectile.....)
	// transition
	// ptr = new transition
	// ptr->addCondition(new enemyinlanecondition)
	// ptr-settargetstate(state::shoot)
	// -> Condition
	// -> targetState
	// bheaviour->addTransition
	// bheaviour->addAction



	Plant* Plant1 = new Plant(sf::Vector2f(10.f, 50.f), plantBehaviour, 1);
	Plant* Plant2 = new Plant(sf::Vector2f(10.f, 150.f), plantBehaviour, 2);
	Plant* Plant3 = new Plant(sf::Vector2f(10.f, 250.f), plantBehaviour, 3);
	Plant* Plant4 = new Plant(sf::Vector2f(10.f, 350.f), plantBehaviour, 4);

	mPlants.push_back(Plant1);
	mPlants.push_back(Plant2);
	mPlants.push_back(Plant3);
	mPlants.push_back(Plant4);
}


Playground* Playground::getInstance()
{
	return sInstance;
}

Playground::~Playground()
{
}

void Playground::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mPlants.size(); i++)
	{
		sf::CircleShape shape(10.f);
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(mPlants[i]->getPosition());
		window.draw(shape);
		/*if (mPlants[i]->mProjectile.size() > 0 && mPlants[i]->shoot())
		{
			std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
			for (int j = 0; j < mPlants[i]->mProjectile.size(); j++)
			{

					sf::CircleShape shape(5.f);
					shape.setFillColor(sf::Color::White);
					shape.setPosition(mPlants[i]->mProjectile[j]->getPosition());
					window.draw(shape);

			}
		}*/
	}
	for (auto& pr : mProjectiles)
	{
		sf::CircleShape shape(5.f);
		shape.setFillColor(sf::Color::White);
		shape.setPosition(pr->getPosition());
		window.draw(shape);
	}
	if (mEnemy.size() > 0)
	{
		for (int i = 0; i < mEnemy.size(); i++)
		{
			sf::CircleShape shape(10.f);
			shape.setFillColor(sf::Color::Red);
			shape.setPosition(sf::Vector2f(mEnemy[i]->getPosition()));
			window.draw(shape);
		}
	}

}

void Playground::update()
{
	for (int i = 0; i < mEnemy.size(); i++)
	{
		mEnemy[i]->Update();
	}
	for (int i = 0; i < mPlants.size(); i++)
	{
		mPlants[i]->Update();
	}
	for (auto & p : mProjectiles)
	{
		p->Update();
	}
	checkCollision();
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i   mousePos = sf::Mouse::getPosition(window);
		int y = 0;
		if (mousePos.y >= 0 && mousePos.y < 100)
		{
			y = 50;
		}
		else if (mousePos.y >= 100 && mousePos.y < 200)
		{
			y = 150;
		}
		else if (mousePos.y >= 200 && mousePos.y < 300)
		{
			y = 250;
		}
		else if (mousePos.y >= 300 && mousePos.y < 400)
		{
			y = 350;
		}

		Enemy* enemy = new Enemy(sf::Vector2f(mousePos.x, y));
		mEnemy.push_back(enemy);
	}
}

void Playground::AddProjectile(sf::Vector2f position)
{
	mProjectiles.push_back(new Projectile(position));
}

const std::vector<Enemy*>& Playground::getEnemies()
{
	return mEnemy;
}
