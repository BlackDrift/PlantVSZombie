#pragma once
#include "Action.hpp"
#include <chrono>

class AddProjectileAction: public Action
{
public:
	AddProjectileAction();
	~AddProjectileAction();
    void Start(Plant* Plant) override;
    void Update(Plant* Plant) override;
    void End(Plant* Plant) override;
private:
    std::chrono::time_point<std::chrono::steady_clock>  mLastShotTime;
};

