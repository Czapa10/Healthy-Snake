#pragma once

#include <vector>
#include <memory>

#include "state.hpp"

namespace States
{


using StateRef = std::unique_ptr<State>;

class StateStack
{
public:
    void pushState(StateRef _newState, bool _isReplacing = true);
    void popState();
    void clearStates();
    void processStateChanges();//run in each frame

    StateRef &getActiveState();
    StateRef &getPreviousState();

    bool areThereTwoStates();

private:
    std::vector<StateRef> states;
    StateRef newState;

    bool isAdding, isReplacing, isRemoving, isClearing;
};


}
