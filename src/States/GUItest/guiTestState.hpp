#pragma once

#include <SFML/Graphics.hpp>
#include <States/State.hpp>
#include <game.hpp>

namespace States
{


class GuiTestState : public State
{
public:
    GuiTestState(Game::GameDataRef data);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    Game::GameDataRef data;
};


}
