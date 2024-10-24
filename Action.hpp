#pragma once

class Plant;

class Action
{
public:
    virtual void Start(Plant * Plant) = 0;
    virtual void Update(Plant * Plant) = 0;
    virtual void End(Plant * Plant) = 0;
};

