#pragma once

#include "State.hpp"
#include "game.hpp"

namespace States
{


class PauseState : public State
{
public:
    PauseState(Game::GameDataRef _data);

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    Game::GameDataRef data;

    sf::Sprite background;

    sf::Clock timeFromChangeState; //to not click Esc as soon as you enter to pause screen

    bool enterWasClicked{false};
    bool escWasClicked{false};
};


}
