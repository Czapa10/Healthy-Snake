#pragma once

#include "State.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "food.hpp"

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

    sf::Clock clock;

    sf::Sprite background;
    Textures::ID tiles[32][24];
    GameElements::Direction spriteRotation[32][24];
    GameElements::Snake snake;
    GameElements::Food food;
    //Food food;
};


}
