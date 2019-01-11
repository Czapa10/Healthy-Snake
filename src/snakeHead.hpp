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
<<<<<<< HEAD
    void init(sf::Vector2i _headPos, Direction _direction, std::vector<Food> _food, Textures::ID _tiles[32][24]);

    void dieAnimation();
    bool showGameOverScreen();

    Textures::ID getCurrentHead();
=======
    Textures::ID getCurrentHead(sf::Vector2i headPos, Direction direction, std::vector<Food> food);
>>>>>>> temp

private:
    bool shouldOpenMouth();//before eat
    bool shouldCloseEyes();//after meal
    bool shouldShowTongue() const;

private:
    sf::Vector2i headPos;
    Direction direction;
    std::vector<Food> food;
    Textures::ID tiles[32][24];

    bool hadOpenMouth;
};


}
