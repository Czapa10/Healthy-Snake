#pragma once

#include "State.hpp"
#include "game.hpp"
#include "board.hpp"

namespace States
{


class GameState : public State
{
public:
    GameState(Game::GameDataRef _data);

    void init();

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    Game::GameDataRef data;

    GameElements::Board board();
};


}
