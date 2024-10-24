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
	std::vector<Projectile*> mProjectiles;
	Playground();
	void checkCollision();
public:
	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);
	void AddProjectile(sf::Vector2f position);

	const std::vector<Enemy*>& getEnemies();
};