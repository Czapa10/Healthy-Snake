#pragma once

#include <vector>

#include "State.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "food.hpp"
#include "statBar.hpp"

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
    void clearTiles();
    void settingFood();
    void foodUpdate();
    void snakeMove();
    void gameOverAnimation();
    void makingSnakeTurnBody( int it, int x, int y, sf::Vector2i previous, sf::Vector2i next );
    void makeSpecificTurnBody( GameElements::Direction _1, GameElements::Direction _2, GameElements::Direction _3, GameElements::Direction _4, bool isTeleporting, int XorY, int nextXorY, int x, int y);
    void afterTeleportTurnTransformations( int & x, int & y, sf::Vector2i & next );
    bool checkIsTeleporting( sf::Vector2i previous, int x, int y );

private:
    Game::GameDataRef data;

    sf::Clock clock;

    sf::Sprite background;
    Textures::ID tiles[32][24];
    GameElements::Direction spriteRotation[32][24];
    GameElements::Snake snake;
    GameElements::StatBar statisticsBar;
    std::vector<GameElements::Food> food;
    int numberOfMealsOnTheScreen{190};
    int points{};

    sf::Clock timeToShowGameOverScreen;
    bool freeze{false};
};


}
