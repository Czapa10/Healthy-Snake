#pragma once

#include <SFML/Graphics.hpp>
#include <game.hpp>

namespace GUI
{


class Button
{
protected:
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, float scaleFactor = 4, bool isActive = true);
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, float scaleFactor = 4, bool isActive = true);

    sf::Text& getText(){ return text; }

protected:
    Game::GameDataRef data;

    const bool isActive;

    bool isPointed = false;
    sf::Text text;
    sf::Vector2i clickBoxExpand;
};


}
