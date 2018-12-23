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

    enum Sprite
    {
        head,
        straightBody,
        turnBody,
        tail
    };

    Direction direction;

    Sprite sprite;

    BodyPart(sf::Vector2i _pos, Sprite _sprite, Direction _direction);
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

public:
    std::vector<BodyPart> bodyParts;

private:
    std::vector<int> addToTail;
    int snakeLength = 5;
    Direction direction;
    bool wasClicked{false};//in this position
};


}
