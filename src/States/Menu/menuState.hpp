#pragma once

#include <SFML/Graphics.hpp>

#include <states/state.hpp>
#include <game.hpp>
#include <GUI/buttonContainer.hpp>

namespace States
{


class MenuState : public State
{
public:
    MenuState(Game::GameDataRef _data);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    void changingState();

private:
    Game::GameDataRef data;

    sf::Sprite background;
    GUI::ButtonContainer buttons;

};


}
