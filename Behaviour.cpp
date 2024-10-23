#include "Behaviour.hpp"
#include "Action.hpp"

#include "Plant.hpp"
#include "Transition.hpp"

Behaviour::Behaviour()
{
}

Behaviour::~Behaviour()
{
    for (auto it : mTransitions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }

    for (auto it : mActions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }
}

void Behaviour::AddTransition(Context::State key, Transition* value)
{
    mTransitions[key].push_back(value);
}

void Behaviour::AddAction(Context::State key, Action* value)
{
    mActions[key].push_back(value);
}

void Behaviour::Start(Plant * Plant)
{
    for (const auto & a : mActions[Plant->getState()])
    {
        a->Start(Plant);
    }
}

void Behaviour::Update(Plant * Plant)
{
    for (const auto & a : mActions[Plant->getState()])
    {
        a->Update(Plant);
    }

    for (const auto & a : mTransitions[Plant->getState()])
    {
        a->Try(Plant);
    }
}


void Behaviour::End(Plant * Plant)
{
    for (const auto & a : mActions[Plant->getState()])
    {
        a->End(Plant);
    }
}

