#include "gameState.hpp"

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
{
}

void GameState::init()
{
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 48; j++){
            tiles[i][j] = Textures::gameBackground;
        }
    }
}

void GameState::input()
{

}

void GameState::update(sf::Time deltaTime)
{

}

void GameState::draw()
{
    data->window.clear();
/*
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 48; j++){
            sf::Sprite sprite;
            sprite.setTexture(data->textures.get(tiles[i][j]));
            sprite.setPosition(sf::Vector2f(i * 16, 48 + j * 16));
            data->window.draw(sprite);
        }
    }
*/
    data->window.display();
}


}
