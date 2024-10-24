#include "ReloadAction.h"
#include "Playground.h"


ReloadAction::ReloadAction()
{
    mStartTime = std::chrono::steady_clock::now(); 
}

ReloadAction::~ReloadAction()
{
}

void ReloadAction::Start(Plant* plant)
{
    mStartTime = std::chrono::steady_clock::now();
}


void ReloadAction::Update(Plant* plant)
{

    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - mStartTime;

    if (elapsedTime.count() >= 3.0f)
    {
        plant->refillMagazine();
    }
}


void ReloadAction::End(Plant* plant)
{

}
