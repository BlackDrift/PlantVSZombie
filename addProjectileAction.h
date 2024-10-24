#pragma once
#include "Action.hpp"

class AddProjectileAction: public Action
{
public:
	AddProjectileAction();
	~AddProjectileAction();
    void Start(Plant* Plant) override;
    void Update(Plant* Plant) override;
    void End(Plant* Plant) override;
private:

};

