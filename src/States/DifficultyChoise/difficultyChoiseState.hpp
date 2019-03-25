#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include <game.hpp>
#include <States/State.hpp>
#include <GUI/buttonContainer.hpp>
#include "bestScoresDisplayer.hpp"

namespace States
{


class DifficultyChoiseState : public State
{
public:
    DifficultyChoiseState(Game::GameDataRef _data);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    void changingState();

private:
    Game::GameDataRef data;

    sf::Sprite background;
    GUI::ButtonContainer buttons;
    BestScoresDisplayer bestScoresDisplayer;
};


}
