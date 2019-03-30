#pragma once

#include <SFML/Graphics.hpp>
#include <game.hpp>

namespace GUI
{


class Button
{
public:
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, float scaleFactor = 4, bool isActive = true);
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, float scaleFactor = 4, bool isActive = true);

    Button(Game::GameDataRef data, const Fonts::ID&, const std::string&, sf::Vector2f pos, unsigned int fontSize = 50, bool isActive = true);
    Button(Game::GameDataRef data, const Fonts::ID&, const std::string&, sf::Vector2f pos, sf::Vector2i clickBoxExpand, unsigned int fontSize = 50, bool isActive = true);

    void display();

    void makeButtonPointed(bool buttonIsPointed);
    bool isMouseOnButton(sf::Vector2i &currentPos);
    bool isClicked(sf::Vector2i &currentPos);

    sf::Sprite& getSprite(){ return sprite; }
    sf::Text& getText(){ return text; }

private:
    Game::GameDataRef data;

    const bool isActive;
    bool isPointed = false;

    sf::IntRect notPointedRect;
    sf::IntRect pointedRect;
    sf::Sprite sprite;
    sf::Text text;
    sf::Vector2i clickBoxExpand;

    enum class ButtonType{ spriteButton, textButton };
    ButtonType type;
};


}
