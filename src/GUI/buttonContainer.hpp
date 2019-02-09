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
    ButtonContainer(Game::GameDataRef data, Textures::ID texture, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2i offset = sf::Vector2i(0,0), bool symmetricSpaceBetweenButtons = true);

    void display();
    //operator[]; - access to certain button

private:
    Game::GameDataRef data;

    const int numberOfButtons;
    const int spaceBetweenButtons;
    sf::Vector2i buttonSize;
    sf::Vector2i offset;
    bool symmetricSpaceBetweenButtons;

    std::vector<Button> buttons;
};


}
