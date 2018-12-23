#include "snake.hpp"

#include <iostream>

namespace GameElements
{


BodyPart::BodyPart(sf::Vector2i _pos, Sprite _sprite, Direction _direction)
:pos(_pos)
,sprite(_sprite)
,direction(_direction)
{
}

Snake::Snake()
{
    direction = Direction::left;

    BodyPart head(sf::Vector2i(12,10), BodyPart::head, Direction::left);
    bodyParts.push_back(head);

    {BodyPart middle(sf::Vector2i(13,10), BodyPart::straightBody, Direction::left);
    bodyParts.push_back(middle);}

    {BodyPart middle(sf::Vector2i(14,10), BodyPart::straightBody, Direction::left);
    bodyParts.push_back(middle);}

    {BodyPart middle(sf::Vector2i(15,10), BodyPart::straightBody, Direction::left);
    bodyParts.push_back(middle);}

    BodyPart tail(sf::Vector2i(16,10), BodyPart::tail, Direction::left);
    bodyParts.push_back(tail);
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

    for(int i = snakeLength; i > 0; --i){
        bodyParts[i] = bodyParts[i - 1];
    }

    if(direction == Direction::left){
        bodyParts[0].pos.x -= 1;

        if(bodyParts[0].pos.x == -1){
            bodyParts[0].pos.x = 32;
        }
    }
    else if(direction == Direction::right){
        bodyParts[0].pos.x += 1;

        if(bodyParts[0].pos.x == 33){
            bodyParts[0].pos.x = 0;
        }
    }
    else if(direction == Direction::up){
        bodyParts[0].pos.y -= 1;

        if(bodyParts[0].pos.y == -1){
            bodyParts[0].pos.y = 24;
        }
    }
    else if(direction == Direction::down){
        bodyParts[0].pos.y += 1;

        if(bodyParts[0].pos.y == 25){
            bodyParts[0].pos.y = 0;
        }
    }

    bodyParts[0].direction = direction;

    for(int i = 0; i < snakeLength; ++i){
        std::cout<<bodyParts[i].pos.x<<" "<<bodyParts[i].pos.y<<"      ";
    }
    std::cout<<std::endl;
}

void Snake::eat()
{

}

void Snake::grow()
{

}


}
