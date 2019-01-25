#pragma once

#include <vector>
#include <array>

#include <States/State.hpp>
#include <game.hpp>
#include <GameElements/snake.hpp>
#include <GameElements/food.hpp>
#include <GameElements/statBar.hpp>

namespace States
{


class GameState : public State
{
public:
    GameState(Game::GameDataRef _data);

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    void updatingSnake();
    void clearTiles();
    void settingFood();
    void foodUpdate();
    void snakeMove();
    void smallMove();
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
    Textures::ID headTexture{Textures::snakeHead};
    std::vector<GameElements::Food> food;
    int numberOfMealsOnTheScreen;
    int howManyCellsOnEachFood;
    int points{};

    bool freeze{false};
    bool hasDyingTimeBeedRestarted{false};
    sf::Clock dyingTime;

    sf::Clock smallMoveClock;
    int numberOfPixelsToMoveSprite{};
};


}
