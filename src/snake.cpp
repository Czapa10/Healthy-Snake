#include "snake.hpp"

#include <iostream>

namespace GameElements
{


BodyPart::BodyPart(sf::Vector2i _pos, Sprite _sprite)
:pos(_pos)
,sprite(_sprite)
{
}

Snake::Snake()
{
    direction = Direction::left;

    BodyPart head(sf::Vector2i(12,10), BodyPart::head);
    bodyParts.push_back(head);

    BodyPart middle(sf::Vector2i(13,10), BodyPart::straightBody);
    bodyParts.push_back(middle);

    BodyPart tail(sf::Vector2i(14,10), BodyPart::tail);
    bodyParts.push_back(tail);
}

void Snake::control()
{
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
}

void Snake::move(Textures::ID tiles[32][24])
{
    tiles[bodyParts[snakeLength].pos.x][bodyParts[snakeLength].pos.y] = Textures::nothing;

    for(int i = 1; i < snakeLength; ++i){
        bodyParts[i].pos = bodyParts[i - 1].pos;
    }

    if(direction == Direction::left){
        bodyParts[0].pos.x -= 1;
    }
    else if(direction == Direction::right){
        bodyParts[0].pos.x += 1;
    }
    else if(direction == Direction::up){
        bodyParts[0].pos.y -= 1;
    }
    else if(direction == Direction::down){
        bodyParts[0].pos.y += 1;
    }

    for(int i = 0; i < snakeLength; ++i){
        std::cout<<bodyParts[i].pos.x<<" "<<bodyParts[i].pos.x<<"      ";
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
