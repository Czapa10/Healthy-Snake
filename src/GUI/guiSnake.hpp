#pragma once

#include <game.hpp>

namespace GUI
{


class GuiSnake
{
public:
    GuiSnake(Game::GameDataRef data);

    update(sf::Vector2f posOfPointedButton);
    display();

private:
    Game::GameDataRef data;
};


}
