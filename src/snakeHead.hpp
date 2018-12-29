#pragma once

#include "resourceIdentifiers.hpp"

namespace GameElements
{


class SnakeHead
{
public:
    Textures::ID getCurrentHead();

private:
    bool showTongue();
    bool openMouthBeforeEat();
    bool closeEyesAfterMeal();
    bool dieAnimation();
};


}
