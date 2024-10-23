#include "Plant.hpp"
#include "Behaviour.hpp"


Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)
{
	mPosition = position;
	mBehaviour = plant_behaviour;
	mAmmoCount = ammo_count;
	mMaxAmmo = ammo_count;
	setState(Context::State::idle);
	for (int i = 0; i < mMaxAmmo; i++)
	{
		mProjectile.push_back(new Projectile(mPosition));
	}
}

void Plant::setState(Context::State state)
{
	mState = state;
}

void Plant::refillMagazine()
{
}

bool Plant::shoot()
{

	return true;
}

void Plant::Update()
{
}


