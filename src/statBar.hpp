#pragma once

#include <SFML/Graphics.hpp>

namespace GameElements
{


class StatBar
{
public:
    StatBar();
    void draw(int points, int snakeLength, int inStomach);

private:
    sf::Sprite barBackground;
};


}
