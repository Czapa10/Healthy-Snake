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

    Button(Game::GameDataRef data, const Fonts::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, unsigned int fontSize = 50, bool isActive = true);
    Button(Game::GameDataRef data, const Fonts::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, unsigned int fontSize = 50, bool isActive = true);

    void update();
    void display();

    void makeButtonPointed(bool buttonIsPointed);
    bool isMouseOnButton(sf::Vector2i &currentPos);
    bool isClicked(sf::Vector2i &currentPos);

    sf::Sprite& getSprite(){ return sprite; }

public:
    bool isPointed = false;

private:
    Game::GameDataRef data;

    const bool isActive;

    sf::IntRect notPointedRect;
    sf::IntRect pointedRect;
    sf::Sprite sprite;
    sf::Vector2i clickBoxExpand;
};


}
