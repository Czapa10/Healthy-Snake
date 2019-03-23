#pragma once

#include <States/State.hpp>
#include <GUI/buttonContainer.hpp>
#include <game.hpp>

namespace States
{


class CreditsState : public State
{
public:
    CreditsState(Game::GameDataRef);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    Game::GameDataRef data;

    GUI::ButtonContainer mainLabels;
    GUI::ButtonContainer specialThanks;
    sf::Sprite background;

    bool shouldComeBackToMenu;
};


}
