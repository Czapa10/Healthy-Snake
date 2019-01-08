#include "snakeHead.hpp"

namespace GameElements
{


Textures::ID SnakeHead::getCurrentHead(Textures::ID tiles[32][24])
{
    ///here will be dying animation

    if(showTongue()){
        return Textures::snakeHeadTounge;
    }
    else if(openMouthBeforeEat(tiles)){
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

bool SnakeHead::openMouthBeforeEat(Textures::ID tiles[32][24])
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
