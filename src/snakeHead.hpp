#pragma once

#include <SFML/Graphics.hpp>

#include "resourceIdentifiers.hpp"

namespace GameElements
{


class Food;

class SnakeHead
{
public:
    Textures::ID getCurrentHead(sf::Vector2i headPos, std::vector<Food> food);

private:
    bool showTongue();
    bool openMouthBeforeEat();
    bool closeEyesAfterMeal();
    bool dieAnimation();
};


}
