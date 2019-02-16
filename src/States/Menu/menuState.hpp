#pragma once

#include <SFML/Graphics.hpp>

#include <states/state.hpp>
#include <game.hpp>

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
    void changingState() const;

private:
    Game::GameDataRef data;

    sf::Sprite background;

};


}
