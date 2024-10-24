#pragma once
#include "Action.hpp"
#include <chrono>

class ReloadAction : public Action
{
public:
    ReloadAction();
    ~ReloadAction();
    void Start(Plant* Plant) override;
    void Update(Plant* Plant) override;
    void End(Plant* Plant) override;
private:
    std::chrono::time_point<std::chrono::steady_clock>  mStartTime;
};

