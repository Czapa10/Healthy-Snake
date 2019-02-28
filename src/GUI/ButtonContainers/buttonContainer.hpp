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
    void update();
    int& getSignal(){return signal;}
    GuiSnake& getSnake(){return snake;}

private:
    void keyboardControls();

private:
    Game::GameDataRef data;

    GuiSnake snake;

    int isOnButtonNr{};
    sf::Clock timeSinceLastClick;
    sf::Vector2i currentMousePos;
    sf::Vector2i lastMousePos;
    int signal{-1};

    const int numberOfButtons;
    const int spaceBetweenButtons;
    sf::Vector2i offset;
};


}
