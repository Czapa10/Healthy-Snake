#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

#include "resourceIdentifiers.hpp"
#include "snakeHead.hpp"
#include "food.hpp"

namespace GameElements
{


enum class Direction
{
    up,
    down,
    right,
    left,
    none
};


struct BodyPart
{
    BodyPart(sf::Vector2i _pos, Direction _direction);

    sf::Vector2i pos;

    Direction direction;
};


class Snake
{
public:
    Snake();
    void control();
    void move();
    void eat(int foodWeight);
    void grow();
    bool isCollideWithItself(Textures::ID tiles[32][24]);

    int getLength(){return snakeLength;}
    int getInStomach(){return foodInStomach;}
    float getSpeed(){return speed;}
    Textures::ID getSnakeHeadTexture(std::vector<Food> food){return head.getCurrentHead(bodyParts.front().pos, currentDirection, food);}
    void setSpeed(float newSpeed){speed = newSpeed;}
    Direction getDirection();

public:
    std::vector<BodyPart> bodyParts;

private:
    SnakeHead head;
    int snakeLength = 3;
    int foodInStomach{};
    float speed{0.12};// 1s / speed = one move on frame

    std::queue<Direction> inputQueue;
    Direction currentDirection;
    bool isThereNewDirectionForThisMove{false};
};


}
