#include "Plant.hpp"
#include "Behaviour.hpp"


Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int hp)
{
	mPosition = position;
	mBehaviour = plant_behaviour;
	mAmmoCount = ammo_count;
	mMaxAmmo = ammo_count;
	setState(Context::State::idle);
	mHp = hp;
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
	mAmmoCount = mMaxAmmo;
}

void Plant::dimHp()
{
	mHp--;
}



void Plant::Update()
{

	if (mState != mLastState)
	{
		mBehaviour->End(this);  
		mBehaviour->Start(this); 
		mLastState = mState; 
	}

	mBehaviour->Update(this);
}


