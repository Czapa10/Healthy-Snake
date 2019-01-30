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

Snake::Snake(Difficulty::Level level)
{
    inputQueue.push(Direction::left);

    bodyParts.reserve(256);

    for(int i = 0; i < snakeLength; ++i){
        BodyPart part(sf::Vector2i(i + 10, 10), Direction::left);
        bodyParts.emplace_back(part);
    }

    switch(level){
        case Difficulty::easy:
            speed = 0.16;
            //speed = 2;
            break;

        case Difficulty::medium:
            speed = 0.12;
            break;

        case Difficulty::hard:
            speed = 0.08;
            break;
    }
}

void Snake::control()
{
    if(inputQueue.size() < 3){
        Direction direction{Direction::none};

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&(inputQueue.front() != Direction::down)){
            direction = Direction::up;
        }
        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))&&(inputQueue.front() != Direction::up)){
            direction = Direction::down;
        }
        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))&&(inputQueue.front() != Direction::right)){
            direction = Direction::left;
        }
        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))&&(inputQueue.front() != Direction::left)){
            direction = Direction::right;
        }

        if((direction != Direction::none)&&(inputQueue.back() != direction)){
            if(isThereNewDirectionForThisMove){
                inputQueue.push(direction);
            }
            else{
                inputQueue.pop();
                inputQueue.push(direction);
                isThereNewDirectionForThisMove = true;
            }
        }
    }
}

void Snake::move()
{
    std::copy_backward(bodyParts.begin(), bodyParts.end() - 1, bodyParts.end());

    isThereNewDirectionForThisMove = false;

    currentDirection = inputQueue.front();

    bodyParts[0].direction = currentDirection;
    if(inputQueue.size() > 1){
        inputQueue.pop();
    }

    if(currentDirection == Direction::left){
        bodyParts[0].pos.x -= 1;

        if(bodyParts[0].pos.x == -1){
            bodyParts[0].pos.x = 31;
        }
    }
    else if(currentDirection == Direction::right){
        bodyParts[0].pos.x += 1;

        if(bodyParts[0].pos.x == 32){
            bodyParts[0].pos.x = 0;
        }
    }
    else if(currentDirection == Direction::up){
        bodyParts[0].pos.y -= 1;

        if(bodyParts[0].pos.y == -1){
            bodyParts[0].pos.y = 23;
        }
    }
    else if(currentDirection == Direction::down){
        bodyParts[0].pos.y += 1;

        if(bodyParts[0].pos.y == 24){
            bodyParts[0].pos.y = 0;
        }
    }
}

void Snake::eat(int foodWeight)
{
    foodInStomach += foodWeight;
}

void Snake::grow()
{
    if(!foodInStomach){
        return;
    }

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

    bodyParts.emplace_back(tail);

    ++snakeLength;
    --foodInStomach;
}

bool Snake::isCollideWithItself(Textures::ID tiles[32][24]) const
{
    int headX = bodyParts[0].pos.x;
    int headY = bodyParts[0].pos.y;

    Textures::ID colisionObject;

    Direction currentDirection {inputQueue.front()};

    if(currentDirection == Direction::left){
        colisionObject = tiles[headX][headY];
    }
    else if(currentDirection == Direction::right){
        colisionObject = tiles[headX][headY];
    }
    else if(currentDirection == Direction::up){
        colisionObject = tiles[headX][headY];
    }
    else if(currentDirection == Direction::down){
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

Direction Snake::getDirection() const
{
    return inputQueue.front();
}



}
