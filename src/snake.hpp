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

    Sprite sprite;

    BodyPart(sf::Vector2i _pos, Sprite _sprite);
};

class Snake
{
public:
    Snake();
    void control();
    void move(Textures::ID tiles[32][24]);
    void eat();
    void grow();

public:
    std::vector<BodyPart> bodyParts;

private:
    std::vector<int> addToTail;
    int snakeLength = 3;
    Direction direction;
};


}
