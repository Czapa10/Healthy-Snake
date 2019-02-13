#pragma once

#include <SFML/Graphics.hpp>
#include <game.hpp>

namespace GUI
{


class Button
{
public:
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2f scaleFactor = sf::Vector2f(4.f, 4.f), bool isActive = true);
    Button(Game::GameDataRef data, const Textures::ID&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, sf::Vector2f scaleFactor = sf::Vector2f(4.f, 4.f), bool isActive = true);

    void update();
    void display();

    void makeButtonPointed(bool buttonIsPointed);

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
