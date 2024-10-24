#include "addProjectileAction.h"
#include "Playground.h"

const float SHOOTING_INTERVAL = 1.0f; 

AddProjectileAction::AddProjectileAction()
{
	mLastShotTime = std::chrono::steady_clock::now(); 
}

AddProjectileAction::~AddProjectileAction()
{
}

void AddProjectileAction::Start(Plant* plant)
{
	mLastShotTime = std::chrono::steady_clock::now();
}


void AddProjectileAction::Update(Plant* plant)
{
    if (plant->getAmmoCount() > 0)
    {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - mLastShotTime;

        if (elapsedTime.count() >= SHOOTING_INTERVAL)
        {
            Playground::getInstance()->AddProjectile(plant->getPosition());

            plant->dimAmmoCount();

            mLastShotTime = std::chrono::steady_clock::now();
        }
    }
}


void AddProjectileAction::End(Plant* plant)
{

}
