#include "snake.hpp"

#include <algorithm>
#include <iostream>

namespace GameElements
{


BodyPart::BodyPart(sf::Vector2i _pos, Direction _direction)
:pos(_pos)
,direction(_direction)
{
}

Snake::Snake()
{
    direction = Direction::left;

    bodyParts.reserve(256);

    for(int i = 0; i < snakeLength; i++){
        BodyPart part(sf::Vector2i(i + 10, 10), Direction::left);
        bodyParts.push_back(part);
    }
}

void Snake::control()
{
    if(!wasClicked){
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&(direction != Direction::down)){
            direction = Direction::up;
        }
        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))&&(direction != Direction::up)){
            direction = Direction::down;
        }
        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))&&(direction != Direction::right)){
            direction = Direction::left;
        }
        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))&&(direction != Direction::left)){
            direction = Direction::right;
        }

        wasClicked = true;
    }
}

void Snake::move()
{
    wasClicked = false;

    std::copy_backward(bodyParts.begin(), bodyParts.end() - 1, bodyParts.end());

    bodyParts[0].direction = direction;

    if(direction == Direction::left){
        bodyParts[0].pos.x -= 1;

        if(bodyParts[0].pos.x == -1){
            bodyParts[0].pos.x = 31;
        }
    }
    else if(direction == Direction::right){
        bodyParts[0].pos.x += 1;

        if(bodyParts[0].pos.x == 32){
            bodyParts[0].pos.x = 0;
        }
    }
    else if(direction == Direction::up){
        bodyParts[0].pos.y -= 1;

        if(bodyParts[0].pos.y == -1){
            bodyParts[0].pos.y = 23;
        }
    }
    else if(direction == Direction::down){
        bodyParts[0].pos.y += 1;

        if(bodyParts[0].pos.y == 24){
            bodyParts[0].pos.y = 0;
        }
    }
}

void Snake::eat()
{
    grow();
}

void Snake::grow()
{
    static sf::Clock clock;

    int x{}, y{};

    if(bodyParts.back().direction == Direction::up){
        x = bodyParts.back().pos.x;
        y = bodyParts.back().pos.y + 1;
    }
    else if(bodyParts.back().direction == Direction::down){
        x = bodyParts.back().pos.x;
        y = bodyParts.back().pos.y - 1;
    }
    else if(bodyParts.back().direction == Direction::left){
        x = bodyParts.back().pos.x + 1;
        y = bodyParts.back().pos.y;
    }
    else if(bodyParts.back().direction == Direction::right){
        x = bodyParts.back().pos.x - 1;
        y = bodyParts.back().pos.y;
    }

    BodyPart tail(sf::Vector2i(x,y), bodyParts.back().direction);

    bodyParts.push_back(tail);

    snakeLength++;
    std::cout<<"length: "<<snakeLength<<std::endl;

    clock.restart();
}

bool Snake::isCollideWithItself(Textures::ID tiles[32][24])
{
    int headX = bodyParts[0].pos.x;
    int headY = bodyParts[0].pos.y;

    Textures::ID colisionObject;

    if(direction == Direction::left){
        colisionObject = tiles[headX][headY];
    }
    else if(direction == Direction::right){
        colisionObject = tiles[headX][headY];
    }
    else if(direction == Direction::up){
        colisionObject = tiles[headX][headY];
    }
    else if(direction == Direction::down){
        colisionObject = tiles[headX][headY];
    }

    switch(colisionObject){
        case Textures::snakeHead:
        case Textures::snakeStraightBody:
        case Textures::snakeTail:
        case Textures::snakeTurnBody:
            return true;
        default:
            return false;
    }
}


}
