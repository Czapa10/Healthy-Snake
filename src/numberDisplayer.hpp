#pragma once

#include <SFML/Graphics.hpp>

#include "game.hpp"

namespace GameElements
{


enum class Number{_0, _1, _2, _3, _4, _5, _6, _7, _8, _9};

class NumberDisplayer
{
public:
    NumberDisplayer(Game::GameDataRef _data, int _x, int _y);
    void display(int toDisplay);

private:
    Game::GameDataRef data;

    int x;
    int y;
};


}
