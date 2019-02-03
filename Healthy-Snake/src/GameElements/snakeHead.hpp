#pragma once

#include <SFML/Graphics.hpp>

#include <Resources/resourceIdentifiers.hpp>

namespace GameElements
{


class Food;
enum class Direction;

class SnakeHead
{
public:
    Textures::ID getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food);

private:
    bool shouldOpenMouth(sf::Vector2i & headPos, Direction & direction, std::vector<Food> & food);//before eat
    bool shouldCloseEyes(Direction & direction);//after meal
    bool shouldShowTongue() const;

private:
    bool hadOpenMouth;
};


}
