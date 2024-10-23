#pragma once

class Plant;

class Condition 
{
public:
    virtual bool Test(Plant * Plant) = 0;
};

class Condition_EnemyInLane : public Condition
{
public:
    bool Test(Plant* plant) override
    {
        // recuperez les mechants a partir de l'instance playground obtenue
        // via getInstance()
        // pour chaque mechant
    }
};