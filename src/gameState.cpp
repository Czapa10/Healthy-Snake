#include "gameState.hpp"
#include "snake.hpp"

#include <iostream>

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
{
}

void GameState::init()
{
    background.setTexture(data->textures.get(Textures::grass));

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            tiles[i][j] = Textures::nothing;
        }
    }
}

void GameState::input()
{
    snake.control();
}

void GameState::update(sf::Time deltaTime)
{
    ///set sprites
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            tiles[i][j] = Textures::nothing;
            //spriteRotation[i][j] = GameElements::Direction::up;
        }
    }

    int it{};//iterator
    for(auto & bodyPart : snake.bodyParts){
        int x = bodyPart.pos.x;
        int y = bodyPart.pos.y;

        sf::Vector2i pervious = snake.bodyParts[it - 1].pos;
        sf::Vector2i next = snake.bodyParts[it + 1].pos;

        spriteRotation[x][y] = bodyPart.direction;

        if(it == 0){
            tiles[x][y] = Textures::snakeHead;
        }
        else if(it == snake.getLength() - 1){
            tiles[x][y] = Textures::snakeTail;
            spriteRotation[x][y] = snake.bodyParts[snake.getLength() - 2].direction;
        }
        else{
            tiles[x][y] = Textures::snakeStraightBody;
        }


        if((pervious.y > bodyPart.pos.y)&&(next.y == bodyPart.pos.y)&&(it != 0)&&(it != snake.getLength() - 1)){
            tiles[x][y] = Textures::snakeTurnBody;

            if(next.x < bodyPart.pos.x){
                spriteRotation[x][y] = GameElements::Direction::down;
            }
            else{
                spriteRotation[x][y] = GameElements::Direction::right;
            }
        }
        else if((pervious.y < bodyPart.pos.y)&&(next.y == bodyPart.pos.y)&&(it != 0)&&(it != snake.getLength() - 1)){
            tiles[x][y] = Textures::snakeTurnBody;

            if(next.x > bodyPart.pos.x){
                spriteRotation[x][y] = GameElements::Direction::up;
            }
            else{
                spriteRotation[x][y] = GameElements::Direction::left;
            }
        }
        else if((pervious.x > bodyPart.pos.x)&&(next.x == bodyPart.pos.x)&&(it != 0)&&(it != snake.getLength() - 1)){
            tiles[x][y] = Textures::snakeTurnBody;

            if(next.y < bodyPart.pos.y){
                spriteRotation[x][y] = GameElements::Direction::up;
            }
            else{
                spriteRotation[x][y] = GameElements::Direction::right;
            }
        }
        else if((pervious.x < bodyPart.pos.x)&&(next.x == bodyPart.pos.x)&&(it != 0)&&(it != snake.getLength() - 1)){
            tiles[x][y] = Textures::snakeTurnBody;

            if(next.y > bodyPart.pos.y){
                spriteRotation[x][y] = GameElements::Direction::down;
            }
            else{
                spriteRotation[x][y] = GameElements::Direction::left;
            }
        }

        ++it;
    }

    ///snake move
    if(clock.getElapsedTime().asSeconds() > 0.11){
        snake.move();
        clock.restart();
    }

    ///test
    /*for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            if(tiles[i][j] == Textures::nothing)
                std::cout<<"not  ";
            else if(tiles[i][j] == Textures::snakeStraightBody)
                std::cout<<"sss  ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n\n\n";*/
    ///test
}

void GameState::draw()
{
    data->window.clear();

    data->window.draw(background);

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            if(tiles[i][j] != Textures::nothing){
                sf::Sprite sprite;
                sprite.setTexture(data->textures.get(tiles[i][j]));
                sprite.setPosition(sf::Vector2f(i * 32 + 16, 48 + j * 32));

                sprite.setOrigin(16.f, 16.f);
                if(spriteRotation[i][j] == GameElements::Direction::left){
                    sprite.rotate(-90.f);
                }
                else if(spriteRotation[i][j] == GameElements::Direction::right){
                    sprite.rotate(90.f);
                }
                else if(spriteRotation[i][j] == GameElements::Direction::down){
                    sprite.rotate(180.f);
                }

                data->window.draw(sprite);
            }
        }
    }

    data->window.display();
}


}