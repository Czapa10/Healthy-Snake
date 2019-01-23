#pragma once

#include <SFML/Graphics.hpp>

#include "numberDisplayer.hpp"
#include <game.hpp>

namespace GameElements
{


class StatBar
{
public:
    StatBar(Game::GameDataRef _data);
    void draw(int points, int snakeLength, int inStomach) const;

private:
    Game::GameDataRef data;

    sf::Sprite barBackground;

    NumberDisplayer pointsDisplayer;
    NumberDisplayer snakeLengthDisplayer;
    NumberDisplayer inStomachDisplayer;
};


}
