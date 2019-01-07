#pragma once

#include <SFML/Graphics.hpp>

namespace States
{


class State
{
public:
    virtual void init() = 0;

    virtual void input() = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw() = 0;
};


}

