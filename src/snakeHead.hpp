#pragma once

#include <SFML/Graphics.hpp>

#include "resourceIdentifiers.hpp"

namespace GameElements
{


class Food;
enum class Direction;

class SnakeHead
{
public:
    Textures::ID getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food);

private:
    bool showTongue();
    bool openMouthBeforeEat(sf::Vector2i & headPos, Direction & direction, std::vector<Food> & food);
    bool closeEyesAfterMeal();
    bool dieAnimation();
};


}
