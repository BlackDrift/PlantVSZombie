#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Context.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Plant
{
    sf::Vector2f mPosition;
    std::string mName;
    int mAmmoCount, mMaxAmmo;
    Context::State mState;
    Behaviour * mBehaviour;
public:
    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Plant() = default;

    void setState(Context::State state);
    Context::State getState() const { return this->mState; }

    sf::Color getColor() const;
    sf::Vector2f getPosition() const { return this->mPosition; }
    int getAmmoCount() const { return this->mAmmoCount; }
    void refillMagazine() ;

    bool shoot();

    void Update();
};
