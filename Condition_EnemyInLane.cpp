#include "Condition_EnemyInLane.h"
#include "Playground.h"

bool Condition_EnemyInLane::Test(Plant* plant)
{
	Playground* mInstance = Playground::getInstance();
	for (auto& e :mInstance->getEnemies())
	{
		if (plant->getPosition().y == e->getPosition().y)
		{
			return true;
		}
	}
	return false;
}
