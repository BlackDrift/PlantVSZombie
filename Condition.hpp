#pragma once

class Plant;

class Condition 
{
public:
    virtual bool Test(Plant * Plant) = 0;
};