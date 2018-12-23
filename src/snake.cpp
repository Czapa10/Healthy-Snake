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

    bodyParts[0].direction = direction;

    if(direction == Direction::left){
        if(bodyParts[0].pos.x == 0){
            bodyParts[0].pos.x = 32;
            return;
        }

        bodyParts[0].pos.x -= 1;
    }
    else if(direction == Direction::right){
        if(bodyParts[0].pos.x == 32){
            bodyParts[0].pos.x = 0;
            return;
        }

        bodyParts[0].pos.x += 1;
    }
    else if(direction == Direction::up){
        if(bodyParts[0].pos.y == 0){
            bodyParts[0].pos.y = 24;
            return;
        }

        bodyParts[0].pos.y -= 1;
    }
    else if(direction == Direction::down){
        bodyParts[0].pos.y += 1;

        if(bodyParts[0].pos.y == 24){
            bodyParts[0].pos.y = 0;
            return;
        }
    }

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
        int x, y;

        std::cout<<"                        HERE 1 !"<<std::endl;

        if(bodyParts.back().direction == Direction::up){
            y = bodyParts.back().pos.y + 1;
        }
        else if(bodyParts.back().direction == Direction::down){
            y = bodyParts.back().pos.y - 1;
        }
        else if(bodyParts.back().direction == Direction::left){
            x = bodyParts.back().pos.x + 1;
        }
        else if(bodyParts.back().direction == Direction::right){
            x = bodyParts.back().pos.x - 1;
        }

        std::cout<<"                        HERE 2 !"<<std::endl;

        BodyPart tail(sf::Vector2i(x,y), BodyPart::tail, bodyParts.back().direction);
        bodyParts.push_back(tail);

        std::cout<<"                        HERE 3 !"<<std::endl;
    }
}


}
