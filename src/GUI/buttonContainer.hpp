#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include <game.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include "button.hpp"

namespace GUI
{


class ButtonContainer
{
public:
    ButtonContainer(Game::GameDataRef data, Textures::ID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2i offset = sf::Vector2i(0,0));

    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button

private:
    Game::GameDataRef data;

    const int numberOfButtons;
    const int spaceBetweenButtons;
    sf::Vector2i buttonSize;
    sf::Vector2i offset;

    std::vector<Button> buttons;
};


}
