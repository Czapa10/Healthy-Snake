#pragma once

#include <stack>
#include <memory>

#include "state.hpp"

namespace States
{

    typedef std::unique_ptr<State> StateRef;

class StateStack
{
public:
    StateStack(){}
    ~StateStack(){}

    void pushState(StateRef _newState, bool _isReplacing = true);
    void popState();
    void processStateChanges();//run in each frame in

    StateRef &getActiveState();

private:
    std::stack<StateRef> states;
    StateRef newState;

    bool isAdding, isReplacing, isRemoving;
};


}
