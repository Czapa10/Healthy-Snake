#include "snakeHead.hpp"

#include "snake.hpp"

namespace GameElements
{


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


}
