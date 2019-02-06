#pragma once

#include <SFML/Graphics.hpp>

namespace States
{


class State
{
public:
    virtual void input() = 0;
    virtual void update(const sf::Time& deltaTime) = 0;
    virtual void draw() = 0;
};


}

