#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

namespace States
{


class SplashState : public State
{
public:
    SplashState(Game::GameDataRef _data);

    void init();

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    Game::GameDataRef data;

    sf::Clock clock;
    sf::Sprite background;
};


}
