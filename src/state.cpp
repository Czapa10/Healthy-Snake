#include "State.hpp"

namespace States
{


State::State(GameData & _gameData)
:gameData(_gameData)
{
}

void State::statePush()
{
    //stateStack.pushState(stateID);
}

void State::statePop()
{
    //stateStack.popState();
}

void State::clearStateStack()
{
    //stateStack.clearStateStack();
}

State::GameData::GameData(sf::RenderWindow & _window, TextureStorage & _textures)
:window(_window)
,textures(_textures)
{
}


}
