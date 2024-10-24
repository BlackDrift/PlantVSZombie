#pragma once
#include "Condition.hpp"

class Condition_shooting : public Condition
{
public:
    bool Test(Plant* plant) override;
};