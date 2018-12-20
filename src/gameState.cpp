#include "gameState.hpp"

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
{
}

GameState::init()
{

}

GameState::input()
{

}

GameState::update(sf::Time deltaTime)
{

}

GameState::draw()
{
    data->window.clear();

    data->window.display();
}


}
