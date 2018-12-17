#pragma once

#include <stack>
#include <memory>
#include <map>

#include "state.hpp"

namespace States
{

    typedef std::unique_ptr<State> StateRef;

class StateStack
{
public:
    explicit StateStack(State::GameData _gameData);

    void pushState(StateRef newState);
    void popState();
    StateRef &getActiveState();

private:
    std::stack<StateRef> states;
    State::GameData gameData;
};


}
