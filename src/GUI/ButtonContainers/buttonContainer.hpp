#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <game.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include <GUI/GuiSnake/guiSnake.hpp>

namespace GUI
{


class ButtonContainer
{
protected:
    ButtonContainer(Game::GameDataRef, const int& numberOfButtons, const int& spaceBetweenButtons, const sf::Vector2i& offset);
    void keyboardControls();

public:
    int& getSignal(){return signal;}

protected:
    Game::GameDataRef data;

    int isOnButtonNr{};
    sf::Clock timeSinceLastClick;
    sf::Vector2i currentMousePos;
    sf::Vector2i lastMousePos = sf::Vector2i();
    int signal{-1};

    const int numberOfButtons;
    const int spaceBetweenButtons;
    const sf::Vector2i offset;
};


}
