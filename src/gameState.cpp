#include "gameState.hpp"

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
{
}

void GameState::init()
{

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

    data->window.display();
}


}
