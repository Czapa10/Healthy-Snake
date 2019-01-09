#include "snakeHead.hpp"

#include "snake.hpp"

#include <iostream>

namespace GameElements
{


Textures::ID SnakeHead::getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food)
{
    ///here will be dying animation

    if(openMouthBeforeEat(headPos, direction, food)){
        return Textures::snakeHeadOpenMouth;
    }
    else if(hasJustEaten){
        return Textures::snakeHeadClosedEyes;
    }
    else if(showTongue()){
        return Textures::snakeHeadTounge;
    }
    else{
        return Textures::snakeHead;
    }
}

bool SnakeHead::showTongue()
{
    return false;
}

bool SnakeHead::openMouthBeforeEat(sf::Vector2i & headPos, Direction & direction, std::vector<Food> & food)
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
        if((meal.getPosition() == inFrontOfHead)||(meal.getPosition() == furtherInFrontOfHead))
            return true;
    }
    return false;
}

bool SnakeHead::closeEyesAfterMeal(sf::Vector2i & headPos, std::vector<Food> & food)
{
    if(hasJustEaten == true){
        hasJustEaten = false;
        return true;
    }

    for(auto meal : food){
        if((headPos.x == meal.getPosition().x)&&(headPos.y == meal.getPosition().y)){
            hasJustEaten = true;
            break;
        }
    }
    return false;
}

bool SnakeHead::dieAnimation()
{
    return false;
}


}
