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
	//mBehaviour->Start(this);
}

void Plant::setState(Context::State state)
{
	mState = state;
}

void Plant::dimAmmoCount()
{
	mAmmoCount--;
}

void Plant::refillMagazine()
{
}

bool Plant::shoot()
{
	//if (m)
	//{

	//}
	return true;
}

void Plant::Update()
{
	mBehaviour->Start(this);
	mBehaviour->Update(this);
	mBehaviour->End(this);
}


