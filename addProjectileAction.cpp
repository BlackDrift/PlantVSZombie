#include "addProjectileAction.h"
#include "Playground.h"

AddProjectileAction::AddProjectileAction()
{
}

AddProjectileAction::~AddProjectileAction()
{
}

void AddProjectileAction::Start(Plant* plant)
{
	Playground* playground = Playground::getInstance();
	if (plant->getAmmoCount() > 0)
	{
		playground->AddProjectile(plant->getPosition());
	}
}


void AddProjectileAction::Update(Plant* plant)
{

}


void AddProjectileAction::End(Plant* plant)
{

}
