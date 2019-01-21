#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "game.hpp"
#include "State.hpp"

namespace States
{


class DifficultyChoiseState : public State
{
public:
    DifficultyChoiseState(Game::GameDataRef _data);

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    Game::GameDataRef data;

    std::array<sf::Sprite, 4> buttons;

    sf::Clock clock;
    int isOnButtonNr{1};
    bool wasClicked{false};
};


}
