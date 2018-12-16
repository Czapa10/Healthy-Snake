#include "stateStack.hpp"

namespace States
{


StateStack::StateStack(State::GameData _gameData)
:gameData(_gameData)
{
}

void StateStack::pushState(ID id)
{
    auto found = stateMap.find(id);

    states.push(*found->second);
}

void StateStack::popState()
{
    states.pop();
}

StateRef &StateStack::getActiveState()
{
    return states.top();
}


}
