#pragma once
#include "Condition.hpp"

class Condition_CanShoot : public Condition
{
public:
    bool Test(Plant* plant) override;
};