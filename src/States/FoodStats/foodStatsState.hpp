#pragma once

#include <States/State.hpp>
#include <game.hpp>

namespace States
{


class FoodStatsState : public State
{
public:
    FoodStatsState(Game::GameDataRef);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    Game::GameDataRef data;
};


}

