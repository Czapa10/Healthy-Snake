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

void StateStack::processStateChanges()
{
    if(isRemoving && !states.empty()){
        states.pop();

        if(!states.empty()){
            states.top()->resume();
        }

        isRemoving = false;
    }

    if(isAdding){
        if(!states.empty()){
            if(isReplacing){
                states.pop();
            }else{
                states.top()->pause();
            }
        }

        states.push(std::move(newState));
        states.top()->init();
        isAdding = false;
    }
}

StateRef &StateStack::getActiveState()
{
    return states.top();
}


}
