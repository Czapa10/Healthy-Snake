#pragma once

#include "square.hpp"
#include "snake.hpp"

namespace GameElements
{


class Board
{
public:
    Board();

    Square tiles[64][48];
    Snake snake;
    //Food food;

};


}
