#include "Plant.hpp"
#include "Behaviour.hpp"


Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)
{
	mPosition = position;
	mBehaviour = plant_behaviour;
	mAmmoCount = ammo_count;
	mMaxAmmo = ammo_count;
	setState(Context::State::idle);
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
	return false;
}

void Plant::Update()
{
}


