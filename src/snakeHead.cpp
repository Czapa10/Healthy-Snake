#include "snakeHead.hpp"

#include "snake.hpp"

#include <iostream>

namespace GameElements
{


void snakeHead::dieAnimation(sf::Vector2i headPos, Direction direction, Textures::ID tiles[32][24])
{
    resetClock();

    Textures::ID newHeadTexture;

    if(dyingTime < 0.7){
        tiles[headPos.x][headPos.y] = Textures::snakeHeadBigEyesWhileDying;
    }
    else if(dyingTime < 1.1){
        tiles[headPos.x][headPos.y] = Textures::snakeHeadClosedEyesWhileDying;
    }
}

bool snakeHead::showGameOverScreen()
{
    return dyingTime > 1.1;
}

Textures::ID SnakeHead::getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food)
{
    ///here will be dying animation

    if(shouldOpenMouth(headPos, direction, food)){
        return Textures::snakeHeadOpenMouth;
    }
    if(shouldCloseEyes(direction)){
        return Textures::snakeHeadClosedEyes;
    }
    if(shouldShowTongue()){
        return Textures::snakeHeadTounge;
    }
    return Textures::snakeHead;
}

bool SnakeHead::shouldOpenMouth(sf::Vector2i & headPos, Direction & direction, std::vector<Food> & food)
{
    sf::Vector2i inFrontOfHead = headPos;
    sf::Vector2i furtherInFrontOfHead = headPos;

    switch(direction){
        case Direction::right:
            ++inFrontOfHead.x;
            furtherInFrontOfHead.x += 2;
            break;

        case Direction::left:
            --inFrontOfHead.x;
            furtherInFrontOfHead.x -= 2;
            break;

        case Direction::down:
            ++inFrontOfHead.y;
            furtherInFrontOfHead.y += 2;
            break;

        case Direction::up:
            --inFrontOfHead.y;
            furtherInFrontOfHead.y -= 2;
            break;
    }

    for(auto meal : food){
        if((meal.getPosition() == inFrontOfHead)||(meal.getPosition() == furtherInFrontOfHead)){
            hadOpenMouth = true;
            return true;
        }
    }
    return false;
}

bool SnakeHead::shouldCloseEyes(Direction & direction)
{
    static Direction previousDirection;

    if((hadOpenMouth)&&(previousDirection == direction)){
        hadOpenMouth = false;
        return true;
    }
    hadOpenMouth = false;

    previousDirection = direction;
    return false;
}

bool SnakeHead::shouldShowTongue() const
{
    static int counter{-5}; //counter for show or not show tongue

    ++counter;
    if(counter == 8)
        counter = -20;

    return counter > 0;
}

void resetClock()
{
    static bool hasBeenReseted{false};

    if(!hasBeenReseted){
        dyingTime.restart();
        hasBeenReseted = true;
    }
}


}
