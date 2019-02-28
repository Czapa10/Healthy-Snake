#pragma once

#include <vector>
#include <initializer_list>
#include <string>
#include <SFML/Graphics.hpp>

#include <game.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include <GUI/Buttons/button.hpp>
#include <GUI/GuiSnake/guiSnake.hpp>

namespace GUI
{


class ButtonContainer
{
public:
    ButtonContainer(Game::GameDataRef data, Textures::ID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, float scaleFactor = 4,sf::Vector2i offset = sf::Vector2i(0,0));
    ButtonContainer(Game::GameDataRef data, Fonts::ID, std::vector<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset = sf::Vector2i(0,0), bool areButtonsCentered = true);

    void input();
    void update();
    void display();
    int& getSignal(){return signal;}
    GuiSnake& getSnake(){return snake;}

private:
    void keyboardControls();
    void mouseControls();

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
    const unsigned int fontSize;
    sf::Vector2i offset;
};


}
