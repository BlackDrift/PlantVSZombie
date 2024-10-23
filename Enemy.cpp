#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, Behaviour* enemy_behaviour /*, int ammo_count*/)
{
    mPosition = position;
    mBehaviour = enemy_behaviour;
    mState = Context::State::idle;
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