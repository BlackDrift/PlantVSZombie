#include "Condition_Reload.h"
#include "Playground.h"

bool Condition_Reload::Test(Plant* plant)
{
	if (plant->getAmmoCount() == 0)
	{
		return true;
	}
	return false;
}
