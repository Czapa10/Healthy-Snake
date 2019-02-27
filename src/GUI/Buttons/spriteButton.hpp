#pragma once

#include "button.hpp"

namespace GUI
{


class SpriteButton : public Button
{
public:
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, float scaleFactor = 4, bool isActive = true);
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, float scaleFactor = 4, bool isActive = true);

    void display();

    void makeButtonPointed(bool buttonIsPointed);
    bool isMouseOnButton(sf::Vector2i &currentPos);
    bool isClicked(sf::Vector2i &currentPos);

    sf::Sprite& getSprite(){ return sprite; }

private:
    sf::IntRect notPointedRect;
    sf::IntRect pointedRect;
    sf::Sprite sprite;
};


}
