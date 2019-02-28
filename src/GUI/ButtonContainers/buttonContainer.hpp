#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include <game.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include <GUI/GuiSnake/guiSnake.hpp>

namespace GUI
{


class ButtonContainer
{
protected:
    ButtonContainer(Game::GameDataRef, const int& numberOfButtons, const int& spaceBetweenButtons, const sf::Vector2i& offset);

    int& getSignal(){return signal;}

private:
    void keyboardControls();

private:
    Game::GameDataRef data;

    int isOnButtonNr{};
    sf::Clock timeSinceLastClick;
    sf::Vector2i currentMousePos;
    sf::Vector2i lastMousePos;
    int signal{-1};

    const int numberOfButtons;
    const int spaceBetweenButtons;
    const sf::Vector2i offset;
};


}
