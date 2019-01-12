#include "stateStack.hpp"

namespace States
{


void StateStack::pushState(StateRef _newState, bool _isReplacing)
{
    isAdding = true;
    isReplacing = _isReplacing;

    newState = std::move(_newState);
}

void StateStack::popState()
{
    isRemoving = true;
}

void StateStack::clearStates()
{
    isClearing = true;
}

void StateStack::processStateChanges()
{
    if(isClearing && !states.empty()){
        states.clear();

        isClearing = false;
    }

    if(isRemoving && !states.empty()){
        states.pop_back();

        isRemoving = false;
    }

    if(isAdding){
        if((!states.empty())&&(isReplacing)){
            states.pop_back();
        }

        states.emplace_back(std::move(newState));
        states.back()->init();
        isAdding = false;
    }
}

StateRef &StateStack::getActiveState()
{
    return states.back();
}

StateRef &StateStack::getPreviousState()
{
    return states.front();
}

bool StateStack::areThereTwoStates()
{
    if(states.size() == 2){
        return true;
    }
    return false;
}


}
