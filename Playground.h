#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Plant.hpp"
#include "Enemy.h"
#include <chrono>

class Playground
{
private:
	std::vector<Plant*> mPlants;
	std::vector<Enemy*> mEnemy;
	Playground() = default;
	/*void checkCollision(
		std::vector<Projectile*>& mProjectiles,
		std::vector<Enemy*>& mEnemies);*/
public:
	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);
};