#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position)
{
    mPosition = position;
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