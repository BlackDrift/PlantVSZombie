#pragma once
#include "Context.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>

class Behaviour;

class Enemy
{
    sf::Vector2f mPosition;
    std::string mName;
    //int mAmmoCount, mMaxAmmo; 
    Context::State mState;
    Behaviour* mBehaviour;
    int mSpeed;
public:
    Enemy();
    Enemy(
        sf::Vector2f position,
        Behaviour* enemy_behaviour/*,
        int ammo_count*/);
    ~Enemy();

    void setState(Context::State state);
    Context::State getState() const;

    sf::Color getColor() const;
    sf::Vector2f getPosition() const;
    void Update();
};