#pragma once

#include <States/State.hpp>
#include <GUI/buttonContainer.hpp>
#include <game.hpp>

namespace States
{


class FoodStatsState : public State
{
public:
    FoodStatsState(Game::GameDataRef);

    void input() override;
    void update() override;
    void draw() override;

private:
    Game::GameDataRef data;

    sf::Sprite background;
    sf::Sprite foodList;
    sf::Text toMenu;

    bool shouldComeBackToMenu;
};


}

