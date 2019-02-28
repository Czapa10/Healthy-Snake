#pragma once

#include "button.hpp"

namespace GUI
{


class TextButton : public Button
{
public:
    SpriteButton(Game::GameDataRef data, const Fonts::ID&, const std::string&, sf::Vector2f pos, unsigned int fontSize = 50, bool isActive = true);
    SpriteButton(Game::GameDataRef data, const Fonts::ID&, const std::string&, sf::Vector2f pos, sf::Vector2i clickBoxExpand, unsigned int fontSize = 50, bool isActive = true);

    void display();

    void makeButtonPointed(bool buttonIsPointed);
    bool isMouseOnButton(sf::Vector2i &currentPos);
    bool isClicked(sf::Vector2i &currentPos);

    sf::Text& getText(){ return text; }

private:
    sf::Text text;
};


}