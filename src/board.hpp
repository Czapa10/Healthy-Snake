#pragma once

#include <vector>

#include "square.hpp"
#include "snake.hpp"

namespace GameElements
{


class Board
{
public:
    Board();

    std::vector<Square> tiles;
    Snake snake;
    //Food food;

};


}
