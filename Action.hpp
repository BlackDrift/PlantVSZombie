#pragma once

class Plant;

class Action
{
public:
    virtual void Start(Plant * Plant) = 0;
    virtual void Update(Plant * Plant) = 0;
    virtual void End(Plant * Plant) = 0;
};

// mettre ca dans un fichier addProjectileAction.{cpp, h},
// 
class AddProjectileAction : public Action
{
public:
    void Start(Plant* Plant) override
    {
        // get instance of Playground
        // if (plant->getAmmoCount() > 0)
        // Playground::getInstance()->addProjectile(plant->getPosition());
    }
    void Update(Plant* Plant) override
    {
        
    }
    void End(Plant* Plant) override
    {

    }
};
