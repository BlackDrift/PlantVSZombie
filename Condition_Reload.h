#pragma once
#include "Condition.hpp"

class Condition_Reload : public Condition
{
public:
    bool Test(Plant* plant) override;
};