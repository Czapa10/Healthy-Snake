#pragma once

#include "snake.hpp"
#include "game.hpp"

namespace GameElements
{


class Board
{
public:
    Board();

    void draw(Game::GameDataRef _data);

    Textures::ID tiles[64][48];
    Snake snake;
    //Food food;

};


}
