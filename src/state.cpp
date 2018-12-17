#include "State.hpp"

namespace States
{


State::State(GameData & _gameData, StateStack & _stateStack)
:gameData(_gameData)
,stateStack(_stateStack)
{
}

void State::statePush(std::unique_ptr<State> newState)
{
    stateStack.pushState(newState);
}

void State::statePop()
{
    stateStack.popState();
}

State::GameData::GameData(sf::RenderWindow & _window, Resources::TextureStorage & _textures)
:window(_window)
,textures(_textures)
{
}


}
