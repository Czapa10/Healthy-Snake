#pragma once

#include <SFML/Graphics.hpp>
#include <game.hpp>

namespace GUI
{


class Button
{
protected:


protected:
    Game::GameDataRef data;

    const bool isActive;

    bool isPointed = false;
    sf::Vector2i clickBoxExpand;
};


}
