#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, Behaviour* projectile_behaviour /*, int ammo_count*/)
{
    mPosition = position;
    mBehaviour = projectile_behaviour;
    mState = Context::State::idle;
    mSpeed = 1;
}

sf::Vector2f Projectile::getPosition() const
{
    return mPosition;
}

void Projectile::Update()
{
    mPosition.x++;
}