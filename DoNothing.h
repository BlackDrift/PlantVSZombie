#pragma once
#include "Action.hpp"

class DoNothing : public Action
{
public:
    DoNothing();
    ~DoNothing();
    void Start(Plant* Plant) override;
    void Update(Plant* Plant) override;
    void End(Plant* Plant) override;
private:

};

