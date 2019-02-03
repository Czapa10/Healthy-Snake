#pragma once

#include <States/State.hpp>
#include <game.hpp>

namespace States
{


class GameOverState : public State
{
public:
    GameOverState(Game::GameDataRef _data);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    Game::GameDataRef data;

    sf::Sprite background;

    sf::Time timeFromChangeState; //to not click Esc as soon as you enter to pause screen

    bool enterWasClicked{false};
    bool escWasClicked{false};
};


}
