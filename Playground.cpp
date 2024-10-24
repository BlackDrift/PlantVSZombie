#include "Playground.h"
#include "addProjectileAction.h"
#include "Transition.hpp"
#include "DoNothing.h"
#include "Condition_EnemyInLane.h"
#include "Condition_Reload.h"
#include "Condition_CanShoot.h"
#include "ReloadAction.h"
#include <string>

namespace
{
static Playground* sInstance = nullptr;
}

void Playground::checkCollision()
{
	//collision ball and enemy
	int countProjectile = 0;
	for (auto& pr : mProjectiles)
	{
		int countEnemy = 0;
		for (auto& e : mEnemy)
		{
			if (pr->getPosition().y == e->getPosition().y)
			{
				if (pr->getPosition().x + 5.f >= e->getPosition().x - 10.f && pr->getPosition().x + 5.f <= e->getPosition().x + 10)
				{
					mProjectiles.erase(mProjectiles.begin() + countProjectile);
					countProjectile--;
					mEnemy.erase(mEnemy.begin() + countEnemy);
					countEnemy--;
					mScore++;
				}
			}
			countEnemy++;

		}
		countProjectile++;
	}

	//collision enemy plant
	int countPlant = 0;
	for (auto& p : mPlants)
	{
		int countEnemy = 0;
		for (auto& e : mEnemy)
		{
			if (p->getPosition().y == e->getPosition().y)
			{
				if (p->getPosition().x + 10.f >= e->getPosition().x - 10.f && p->getPosition().x + 10.f <= e->getPosition().x + 10)
				{
					p->dimHp();
					if (p->getHp() == 0)
					{
						mPlants.erase(mPlants.begin() + countPlant);
						countPlant--;
					}
					mEnemy.erase(mEnemy.begin() + countEnemy);
					countEnemy--;
				}
			}
			countEnemy++;

		}
		countPlant++;
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
	if (!mFont.loadFromFile("../Hack-Regular.ttf"))
	{
		std::cout << "Couldn't load the font";
	}
	mScore = 0;
	for (int i = 0; i < 4; ++i) 
	{
		Behaviour* plantBehaviour = new Behaviour();

		plantBehaviour->AddAction(Context::State::idle, new DoNothing());
		Transition* ptr = new Transition;
		ptr->addCondition(new Condition_EnemyInLane());
		ptr->setTargetState(Context::State::shoot);
		plantBehaviour->AddTransition(Context::State::idle, ptr);
		plantBehaviour->AddAction(Context::State::shoot, new AddProjectileAction());


		Transition* ptr2 = new Transition;
		ptr2->addCondition(new Condition_Reload);
		ptr2->setTargetState(Context::State::reload);
		plantBehaviour->AddTransition(Context::State::shoot, ptr2);
		plantBehaviour->AddAction(Context::State::reload, new ReloadAction());


		Transition* ptr3 = new Transition;
		ptr3->addCondition(new Condition_CanShoot);
		ptr3->setTargetState(Context::State::idle);
		plantBehaviour->AddTransition(Context::State::reload, ptr3);
		plantBehaviour->AddAction(Context::State::idle, new DoNothing);

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



		Plant* plant = new Plant(sf::Vector2f(10.f, 50.f + i * 100.f), plantBehaviour, 4 - i, 5);

		mPlants.push_back(plant);
	}
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
	for (auto& p :mPlants)
	{
		sf::CircleShape shape(10.f);
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(p->getPosition());
		window.draw(shape);

		//display Hp
		sf::Text text;
		text.setFont(mFont);
		std::string s = std::to_string(p->getHp());
		text.setString(s);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(p->getPosition().x -10, p->getPosition().y));
		window.draw(text);
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
		for (auto& e: mEnemy)
		{
			sf::CircleShape shape(10.f);
			shape.setFillColor(sf::Color::Red);
			shape.setPosition(sf::Vector2f(e->getPosition()));
			window.draw(shape);
		}
	}
	//display score
	sf::Text text; 
	text.setFont(mFont); 
	std::string s = std::to_string(mScore); 
	text.setString("Score : " + s);
	text.setCharacterSize(24); 
	text.setFillColor(sf::Color::White); 
	text.setPosition(sf::Vector2f(250, 10)); 
	window.draw(text); 
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
		bool isPlant = false;
		for (auto& p : mPlants)
		{
			if (p->getPosition().y == y)
			{
				isPlant = true;
			}
		}
		if (isPlant)
		{
			Enemy* enemy = new Enemy(sf::Vector2f(mousePos.x, y));
			mEnemy.push_back(enemy);
		}

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
