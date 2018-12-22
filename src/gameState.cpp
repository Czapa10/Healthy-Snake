#include "gameState.hpp"

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
    for(auto & bodyPart : snake.bodyParts){
        int x = bodyPart.pos.x;
        int y = bodyPart.pos.y;

        tiles[x][y] = Textures::snakeStraightBody;
    }

    if(clock.getElapsedTime().asSeconds() > 0.16){
        snake.move(tiles);
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
                sprite.setPosition(sf::Vector2f(i * 32, 32 + j * 32));
                data->window.draw(sprite);
            }
        }
    }

    data->window.display();
}


}
