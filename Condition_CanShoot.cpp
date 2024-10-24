#include "Condition_CanShoot.h"
#include "Playground.h"

bool Condition_CanShoot::Test(Plant* plant)
{
	if (plant->getAmmoCount() != 0)
	{
		return true;
	}
	return false;
}
