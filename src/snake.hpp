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
    bool isCollideWithItself(Textures::ID tiles[32][24]);

    int getLength(){return snakeLength;}
    float getSpeed(){return speed;}
    void setSpeed(float newSpeed){speed = newSpeed;}
    Direction getDirection(){return direction;}

public:
    std::vector<BodyPart> bodyParts;

private:
    std::vector<int> addToTail;
    int snakeLength = 9;
    Direction direction;
    bool wasClicked{false};//in this position
    float speed{0.11};// 1s / speed = one move on frame
};


}
