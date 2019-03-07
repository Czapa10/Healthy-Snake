#pragma once

#include <SFML/Graphics.hpp>
#include <game.hpp>

namespace GUI
{


class Button
{
protected:
    Button(Game::GameDataRef, const sf::Vector2i& clickBoxExpand, bool isActive = true );

protected:
    Game::GameDataRef data;

    sf::Vector2i clickBoxExpand;

    bool isPointed;
    const bool isActive;
};


}
