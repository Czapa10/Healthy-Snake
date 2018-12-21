#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace GameElements
{


struct BodyPart
{
    sf::Vector2i pos;

    enum Direction
    {
        up,
        down,
        right,
        left
    };

    Direction direction;

    enum Sprite
    {
        head,
        straightBody,
        turnBody,
        tail
    };

    Sprite sprite;

    BodyPart(sf::Vector2i _pos, Direction _direction, Sprite _sprite);
};

class Snake
{
public:
    Snake();
    void move();
    void eat();
    void grow();

public:
    std::vector<BodyPart> bodyParts;

private:
    std::vector<int> addToTail;
    int snakeLength = 3;
};


}
