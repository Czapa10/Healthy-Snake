#include "snake.hpp"

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

    for(int i = snakeLength; i > 0; --i){
        bodyParts[i] = bodyParts[i - 1];
    }

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

    /*for(int i = 0; i < snakeLength; ++i){
        std::cout<<bodyParts[i].pos.x<<" "<<bodyParts[i].pos.y<<"      ";
    }
    std::cout<<std::endl;*/
}

void Snake::eat()
{
    grow();
}

void Snake::grow()
{
    static sf::Clock clock;

    //try
    //{
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

        std::cout<<"length before: "<<snakeLength<<std::endl;

        BodyPart tail(sf::Vector2i(x,y), bodyParts.back().direction);

        std::cout<<"                        HERE 1 !"<<std::endl;

        bodyParts.push_back(tail);

        std::cout<<"                        HERE 2 !"<<std::endl;

        snakeLength++;
        std::cout<<"length after: "<<snakeLength<<std::endl;

        clock.restart();

    //}
    //catch(const std::exception & except)
    //{
    //    std::cout<<"Exception, what(): "<<except.what();
    //    std::cin.get();
    //}
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
