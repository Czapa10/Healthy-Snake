#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "resourceIdentifiers.hpp"

namespace GameElements
{


enum class Direction
{
    up,
    down,
    right,
    left
};


struct BodyPart
{
    sf::Vector2i pos;

    Direction direction;

    BodyPart(sf::Vector2i _pos, Direction _direction);
};


class Snake
{
public:
    Snake();
    void control();
    void move();
    void eat();
    void grow();

    int getLength(){return snakeLength;}
    Direction getDirection(){return direction;}

public:
    std::vector<BodyPart> bodyParts;

private:
    std::vector<int> addToTail;
    int snakeLength = 9;
    Direction direction;
    bool wasClicked{false};//in this position
};


}
