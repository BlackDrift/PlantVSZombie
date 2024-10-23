#include "Playground.h"


Playground* Playground::instantiate()
{
	Behaviour plantBehaviour;

	Playground* playground = new Playground();
	Plant* Plant1 = new Plant(sf::Vector2f(10.f, 50.f), &plantBehaviour, 1);
	Plant* Plant2 = new Plant(sf::Vector2f(10.f, 150.f), &plantBehaviour, 2);
	Plant* Plant3 = new Plant(sf::Vector2f(10.f, 250.f), &plantBehaviour, 3);
	Plant* Plant4 = new Plant(sf::Vector2f(10.f, 350.f), &plantBehaviour, 4);

	playground->mPlants.push_back(Plant1);
	playground->mPlants.push_back(Plant2);
	playground->mPlants.push_back(Plant3);
	playground->mPlants.push_back(Plant4);

	return playground;
}

Playground* Playground::getInstance()
{
	return nullptr;
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
		if (mPlants[i]->mProjectile.size() > 0 && mPlants[i]->shoot())
		{
			for (int j = 0; j < mPlants[i]->mProjectile.size(); j++)
			{
				std::chrono::system_clock::time_point t = std::chrono::system_clock::now();
				if (std::chrono::system_clock::now() >= t + std::chrono::seconds(1))
				{
					sf::CircleShape shape(5.f);
					shape.setFillColor(sf::Color::White);
					shape.setPosition(mPlants[i]->mProjectile[j]->getPosition());
					window.draw(shape);
				}
			}
		}
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
	if (mEnemy.size() > 0)
	{
		for (int i = 0; i < mEnemy.size(); i++)
		{
			mEnemy[i]->Update();
		}
	}
	for (int i = 0; i < mPlants.size(); i++)
	{
		if (mPlants[i]->mProjectile.size() > 0)
		{
			for (int j = 0; j < mPlants[i]->mProjectile.size(); j++)
			{

				mPlants[i]->mProjectile[j]->Update();
			}
		}
	}
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
