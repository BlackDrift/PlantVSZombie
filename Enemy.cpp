#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position)
{
    mPosition = position;
    mSpeed = 1;
}

sf::Vector2f Enemy::getPosition() const
{
    return mPosition;
}

void Enemy::Update()
{
    mPosition.x--;
}