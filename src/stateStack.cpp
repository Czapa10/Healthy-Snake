#include "stateStack.hpp"

namespace States
{


StateStack::StateStack(State::GameData _gameData)
:gameData(_gameData)
{
}

void StateStack::pushState(StateRef newState)
{
    states.push(std::move(newState));
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
