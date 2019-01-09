#include "snakeHead.hpp"

#include "snake.hpp"

#include <iostream>

namespace GameElements
{


Textures::ID SnakeHead::getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food)
{
    ///here will be dying animation
    std::cout<<"1: "<<hadOpenMouth<<"     ";

    if(openMouthBeforeEat(headPos, direction, food)){
        hadOpenMouth = true;
        return Textures::snakeHeadOpenMouth;
    }
    std::cout<<"2: "<<hadOpenMouth<<std::endl; //it's false
    if(hadOpenMouth){
        hadOpenMouth = false;
        return Textures::snakeHeadClosedEyes;
    }

    if(showTongue()){
        return Textures::snakeHeadTounge;
    }

    return Textures::snakeHead;
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
        if((meal.getPosition() == inFrontOfHead)||(meal.getPosition() == furtherInFrontOfHead)){
            return true;
        }
    }
    return false;
}

bool SnakeHead::showTongue()
{
    return false;
}

bool SnakeHead::dieAnimation()
{
    return false;
}


}
