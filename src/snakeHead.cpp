#include "snakeHead.hpp"

namespace GameElements
{


Textures::ID SnakeHead::getCurrentHead(sf::Vector2i headPos, std::vector<Food> food)
{
    ///here will be dying animation

    if(showTongue()){
        return Textures::snakeHeadTounge;
    }
    else if(openMouthBeforeEat()){
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

bool SnakeHead::openMouthBeforeEat()
{
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
