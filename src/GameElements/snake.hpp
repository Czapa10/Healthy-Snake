#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

#include "resourceIdentifiers.hpp"
#include "difficultyLevelIdentifiers.hpp"
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
    Snake(Difficulty::Level);
    void control();
    void move();
    void eat(int foodWeight);
    void grow();
    bool isCollideWithItself(Textures::ID tiles[32][24]) const;

    int getLength(){return snakeLength;}
    int getInStomach(){return foodInStomach;}
    float getSpeed(){return speed;}
    void setSpeed(float newSpeed){speed = newSpeed;}
    Direction getDirection() const;
    Textures::ID getSnakeHeadTexture(std::vector<Food> food){return head.getCurrentHead(bodyParts.front().pos, currentDirection, food);}

public:
    std::vector<BodyPart> bodyParts;
    SnakeHead head;

private:
    int snakeLength = 3;
    int foodInStomach{};
    float speed;// 1s / speed = one move on frame

    std::queue<Direction> inputQueue;
    Direction currentDirection;
    bool isThereNewDirectionForThisMove{false};
};


}
