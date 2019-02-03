#pragma once

#include <SFML/Graphics.hpp>

#include <States/State.hpp>
#include <game.hpp>

namespace States
{


class SplashState : public State
{
public:
    SplashState(Game::GameDataRef _data);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    Game::GameDataRef data;

    sf::Clock clock;
    sf::Sprite background;

    int whichLogo{};
    bool change{true};
};


}
