#pragma once

#include <stack>
#include <memory>

#include "state.hpp"

namespace States
{


using StateRef = std::unique_ptr<State>;

class StateStack
{
public:
    StateStack(){}
    ~StateStack(){}

    void pushState(StateRef _newState, bool _isReplacing = true);
    void popState();
    void processStateChanges();//run in each frame

    StateRef &getActiveState();

private:
    std::stack<StateRef> states;
    StateRef newState;

    bool isAdding, isReplacing, isRemoving;
};


}
