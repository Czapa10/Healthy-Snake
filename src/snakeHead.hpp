#pragma once

#include "resourceIdentifiers.hpp"

namespace GameElements
{


class SnakeHead
{
public:
    Textures::ID getCurrentHead(Textures::ID tiles[32][24]);

private:
    bool showTongue(Textures::ID tiles[32][24]);
    bool openMouthBeforeEat();
    bool closeEyesAfterMeal();
    bool dieAnimation();
};


}
