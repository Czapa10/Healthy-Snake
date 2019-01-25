#include "gameState.hpp"

#include <GameElements/snake.hpp>
#include <States/GameOver/gameOverState.hpp>
#include <States/Pause/pauseState.hpp>
#include <States/DifficultyChoise/difficultyLevelIdentifiers.hpp>

#include <iostream>

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
,statisticsBar(data)
,snake(data->levelOfDifficulty)
{
    background.setTexture(data->textures.get(Textures::gameBackground));

    clearTiles();

    switch(data->levelOfDifficulty){
        case Difficulty::easy:
            numberOfMealsOnTheScreen = 128;
            howManyCellsOnEachFood = 6;
            break;

        case Difficulty::medium:
            numberOfMealsOnTheScreen = 192;
            howManyCellsOnEachFood = 4;
            break;

        case Difficulty::hard:
            numberOfMealsOnTheScreen = 384;
            howManyCellsOnEachFood = 2;
            break;
    }

    settingFood();
}

void GameState::input()
{
    if(freeze)
        return;

    snake.control();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        std::unique_ptr<States::PauseState> toStack(new States::PauseState(data));
        data->stateStack.pushState(std::move(toStack), false);
    }
}

void GameState::update(sf::Time deltaTime)
{
    if(freeze){
        gameOverAnimation();
        return;
    }

    ///set sprites
    clearTiles();

    updatingSnake();

    foodUpdate();

    snakeMove();
    smallMove();
}

void GameState::draw()
{
    data->window.clear();

    data->window.draw(background);

    sf::Vector2f tailPos;
    GameElements::Direction tailRotation;

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            if(tiles[i][j] != Textures::nothing){
                sf::Sprite sprite;
                sprite.setTexture(data->textures.get(tiles[i][j]));
                sprite.setPosition(sf::Vector2f(i * 32 + 16, j * 32 + 16));

                if(tiles[i][j] == Textures::snakeTail){
                    tailPos.x = sprite.getPosition().x;
                    tailPos.y = sprite.getPosition().y;
                    tailRotation = spriteRotation[i][j];
                    continue;
                }

                sprite.setOrigin(16.f, 16.f);
                if(spriteRotation[i][j] == GameElements::Direction::left){
                    sprite.rotate(-90.f);
                }
                else if(spriteRotation[i][j] == GameElements::Direction::right){
                    sprite.rotate(90.f);
                }
                else if(spriteRotation[i][j] == GameElements::Direction::down){
                    sprite.rotate(180.f);
                }

                data->window.draw(sprite);
            }
        }
    }

    displayTailAndHead(Textures::snakeTail, tailPos, tailRotation);

    statisticsBar.draw(points, snake.getLength(), snake.getInStomach());
}

//*************************************************************************

void GameState::displayTailAndHead(Textures::ID toDisplay, sf::Vector2f pos, GameElements::Direction rotation)
{
    sf::Sprite sprite;
    sprite.setTexture(data->textures.get(toDisplay));
    sprite.setPosition(pos);
    sf::Vector2f smallMoveVec;
    switch(rotation){
        case GameElements::Direction::left:
            smallMoveVec.x -= numberOfPixelsToMoveSprite * 4;
            break;

        case GameElements::Direction::right:
            smallMoveVec.x += numberOfPixelsToMoveSprite * 4;
            break;

        case GameElements::Direction::up:
            smallMoveVec.y -= numberOfPixelsToMoveSprite * 4;
            break;

        case GameElements::Direction::down:
            smallMoveVec.y += numberOfPixelsToMoveSprite * 4;
            break;
    }

    sprite.setOrigin(16.f, 16.f);
    ///change this to switch later
    if(rotation == GameElements::Direction::left){
        sprite.rotate(-90.f);
    }
    else if(rotation == GameElements::Direction::right){
        sprite.rotate(90.f);
    }
    else if(rotation == GameElements::Direction::down){
        sprite.rotate(180.f);
    }

    sprite.move(smallMoveVec);

    data->window.draw(sprite);
}

void GameState::updatingSnake()
{
    int i{};//iterator
    for(auto & bodyPart : snake.bodyParts){
        int x = bodyPart.pos.x;
        int y = bodyPart.pos.y;

        sf::Vector2i previous = snake.bodyParts[i - 1].pos; //(in direction to head)
        sf::Vector2i next = snake.bodyParts[i + 1].pos; //(in direction to tail)

        spriteRotation[x][y] = bodyPart.direction;

        if(i == 0){
            tiles[x][y] = headTexture;
        }
        else if(i == snake.getLength() - 1){
            tiles[x][y] = Textures::snakeTail;
            spriteRotation[x][y] = snake.bodyParts[snake.getLength() - 2].direction;
        }
        else{
            tiles[x][y] = Textures::snakeStraightBody;
        }

        makingSnakeTurnBody(i, x, y, previous, next);

        ++i;
    }
}

void GameState::clearTiles()
{
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            tiles[i][j] = Textures::nothing;
            spriteRotation[i][j] = GameElements::Direction::up;
        }
    }
}

void GameState::settingFood()
{
    for(int i = 0; i < numberOfMealsOnTheScreen; ++i){
        GameElements::Food meal;
        food.emplace_back(meal);
    }
}

void GameState::foodUpdate()
{
    int i{};
    for(auto & meal : food){
        tiles[meal.getPosition().x][meal.getPosition().y] = meal.getTextureID();

        ///eating meal and meal changes its position
        if((snake.bodyParts.front().pos.x == meal.getPosition().x)&&(snake.bodyParts.front().pos.y == meal.getPosition().y)){
            snake.eat(meal.getWeight());
            points += meal.getPoints();

            if(food.size() * howManyCellsOnEachFood > 768 - snake.getLength()){
                food.erase(food.begin() + i);
                std::cout<<food.size()<<std::endl;
            }
            else{
                for(;;){
                    meal.setRandomPos();

                    bool getOut{true};

                    for(auto part : snake.bodyParts){
                        if(meal.getPosition() == part.pos){
                            getOut = false;
                            break;
                        }
                    }

                    if(getOut){
                        for(int j = 0; j < i; ++j){
                            if(meal.getPosition() == food[j].getPosition()){
                                getOut = false;
                                break;
                            }
                        }
                    }

                    if(getOut){
                        for(int j = i + 1; j < food.size(); ++j){
                            if(meal.getPosition() == food[j].getPosition()){
                                getOut = false;
                                break;
                            }
                        }
                    }

                    if(getOut)
                        break;
                }
            }
        }
        ++i;
    }
}

void GameState::snakeMove()
{
    if(clock.getElapsedTime().asSeconds() > snake.getSpeed()){
        snake.move();
        snake.grow();
        headTexture = snake.getSnakeHeadTexture(food);
        clock.restart();

        smallMoveClock.restart();
        numberOfPixelsToMoveSprite = 0;

        ///check collision
        if(snake.isCollideWithItself(tiles)){
            freeze = true;
        }

        std::cout<<"SNAKE MOVES"<<std::endl;
    }
}

void GameState::smallMove()
{
    if(smallMoveClock.getElapsedTime().asSeconds() > snake.getSpeed() / 9){
        ++numberOfPixelsToMoveSprite;
        smallMoveClock.restart();

        std::cout<<"numberOfPixelsToMoveSprite: "<<numberOfPixelsToMoveSprite<<std::endl;
    }
}

void GameState::gameOverAnimation()
{
    if(!hasDyingTimeBeedRestarted){
        dyingTime.restart();
        hasDyingTimeBeedRestarted = true;
    }

    sf::Vector2i headPos = snake.bodyParts.front().pos;

    switch(snake.getDirection()){
        case GameElements::Direction::right:
            --headPos.x;
            break;

        case GameElements::Direction::left:
            ++headPos.x;
            break;

        case GameElements::Direction::down:
            --headPos.y;
            break;

        case GameElements::Direction::up:
            ++headPos.y;
            break;
    }
    if(dyingTime.getElapsedTime().asSeconds() < 0.7){
        tiles[headPos.x][headPos.y] = Textures::snakeHeadBigEyesWhileDying;
    }
    else if(dyingTime.getElapsedTime().asSeconds() < 1.1){
        tiles[headPos.x][headPos.y] = Textures::snakeHeadClosedEyesWhileDying;
    }
    else{
        std::unique_ptr<States::GameOverState> toStack(new States::GameOverState(data));
        data->stateStack.pushState(std::move(toStack), false);
    }
}

void GameState::makingSnakeTurnBody(int i,int x, int y, sf::Vector2i previous, sf::Vector2i next)
{
    afterTeleportTurnTransformations(x, y, next);

    bool isTeleporting = checkIsTeleporting(previous, x, y);

    if((i != 0)&&(i != snake.getLength() - 1)){//if this body part is not head and tail
        if((previous.y > y)&&(next.y == y)){
            makeSpecificTurnBody(GameElements::Direction::left, GameElements::Direction::up,
                                 GameElements::Direction::down, GameElements::Direction::right,
                                 isTeleporting, x, next.x, x, y);
        }
        else if((previous.y < y)&&(next.y == y)){
            makeSpecificTurnBody(GameElements::Direction::down, GameElements::Direction::right,
                                 GameElements::Direction::left, GameElements::Direction::up,
                                 isTeleporting, x, next.x, x, y);
        }
        else if((previous.x > x)&&(next.x == x)){
            makeSpecificTurnBody(GameElements::Direction::left, GameElements::Direction::down,
                                 GameElements::Direction::up, GameElements::Direction::right,
                                 isTeleporting, y, next.y, x, y);
        }
        else if((previous.x < x)&&(next.x == x)){
            makeSpecificTurnBody(GameElements::Direction::up, GameElements::Direction::right,
                                 GameElements::Direction::left, GameElements::Direction::down,
                                 isTeleporting, y, next.y, x, y);
        }
    }
}

void GameState::makeSpecificTurnBody( GameElements::Direction _1, GameElements::Direction _2, GameElements::Direction _3, GameElements::Direction _4,
                                      bool isTeleporting, int XorY, int nextXorY, int x, int y)
{
    tiles[x][y] = Textures::snakeTurnBody;

    if(isTeleporting){
        if(nextXorY < XorY){
            spriteRotation[x][y] = _1;
        }
        else{
            spriteRotation[x][y] = _2;
        }
    }
    else{
        if(nextXorY < XorY){
            spriteRotation[x][y] = _3;
        }
        else{
            spriteRotation[x][y] = _4;
        }
    }
}

void GameState::afterTeleportTurnTransformations( int & x, int & y, sf::Vector2i & next )
{
    if((next.y + 1 != y)&&(next.y - 1 != y)&&(next.y != y)){
        next.y = -next.y;
        if(next.y == 0)
            next.y = 35;
    }
    else if((next.x + 1 != x)&&(next.x - 1 != x)&&(next.x != x)){
        next.x = -next.x;
        if(next.x == 0)
            next.x = 35;
    }
}

bool GameState::checkIsTeleporting( sf::Vector2i previous, int x, int y )
{
    if((x + 1 != previous.x)&&(x - 1 != previous.x)
    &&(x != previous.x)&&(x != previous.x)
    ||(y + 1 != previous.y)&&(y - 1 != previous.y)
    &&(y != previous.y)&&(y != previous.y)){
        return true;
    }
    return false;
}


}
