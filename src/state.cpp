#include "State.hpp"
#include "stateStack.hpp"

namespace States
{


State::State(GameData & _gameData, StateStack & _stateStack)
:gameData(_gameData)
,stateStack(_stateStack)
{
}

void State::statePush(ID id)
{
    //stateStack.pushState(stateID);
}

void State::statePop()
{
    //stateStack.popState();
}

State::GameData::GameData(sf::RenderWindow & _window, Resources::TextureStorage & _textures)
:window(_window)
,textures(_textures)
{
}


}
