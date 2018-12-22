#include "gameState.hpp"

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

}

void GameState::update(sf::Time deltaTime)
{

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
