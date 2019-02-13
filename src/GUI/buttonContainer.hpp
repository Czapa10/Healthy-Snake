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
    ButtonContainer(Game::GameDataRef data, Textures::ID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2f scaleFactor = sf::Vector2f(4.f, 4.f),sf::Vector2i offset = sf::Vector2i(0,0));

    void input();
    void update();
    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button

private:
    Game::GameDataRef data;

    int isOnButtonNr{};
    sf::Clock timeSinceLastClick;
    sf::Vector2i currentMousePos;
    sf::Vector2i lastMousePos;

    const int numberOfButtons;
    const int spaceBetweenButtons;
    sf::Vector2i buttonSize;
    sf::Vector2i offset;

    std::vector<Button> buttons;
};


}
