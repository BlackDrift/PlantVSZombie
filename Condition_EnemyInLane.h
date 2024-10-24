#pragma once
#include "Condition.hpp"

class Condition_EnemyInLane : public Condition
{
public:
    bool Test(Plant* plant) override;
};