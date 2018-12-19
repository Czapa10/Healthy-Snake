#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

namespace States
{


class MenuState : public State
{
public:
    MenuState(Game::GameDataRef _data);

    void init();

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    Game::GameDataRef data;

    sf::Sprite background;
    sf::Text play;
    sf::Text settings;
    sf::Text credits;
    sf::Text bestScore;
    sf::Text exit;
};


}
