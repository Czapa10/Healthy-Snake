#pragma once

#include <SFML/Graphics.hpp>

#include "numberDisplayer.hpp"

namespace GameElements
{


class StatBar
{
public:
    StatBar(sf::Texture & barBackgroundTexture);
    void draw(int points, int snakeLength, int inStomach, sf::RenderWindow & window);

private:
    sf::Sprite barBackground;

    NumberDisplayer pointsDisplayer;
    NumberDisplayer snakeLengthDisplayer;
    NumberDisplayer inStomachDisplayer;
};


}
