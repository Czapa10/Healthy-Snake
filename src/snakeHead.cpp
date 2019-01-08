#include "snakeHead.hpp"

#include "snake.hpp"

namespace GameElements
{


Textures::ID SnakeHead::getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food)
{
    ///here will be dying animation

    if(showTongue()){
        return Textures::snakeHeadTounge;
    }
    else if(openMouthBeforeEat(headPos, direction, food)){
        return Textures::snakeHeadOpenMouth;
    }
    else if(closeEyesAfterMeal()){
        return Textures::snakeHeadClosedEyes;
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

bool SnakeHead::closeEyesAfterMeal()
{
    return false;
}

bool SnakeHead::dieAnimation()
{
    return false;
}


}
