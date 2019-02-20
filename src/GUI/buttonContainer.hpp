#pragma once

#include <vector>
#include <initializer_list>
#include <string>
#include <SFML/Graphics.hpp>

#include <game.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include "button.hpp"
#include "guiSnake.hpp"

namespace GUI
{


class ButtonContainer
{
public:
    ButtonContainer(Game::GameDataRef data, Textures::ID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, float scaleFactor = 4,sf::Vector2i offset = sf::Vector2i(0,0));
    ButtonContainer(Game::GameDataRef data, Fonts::ID, std::initializer_list<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset = sf::Vector2i(0,0));

    void input();
    void update();
    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button
    int& getSignal(){return signal;}
    GuiSnake& getSnake(){return snake;}

private:
    void keyboardControls();
    void mouseControls();

private:
    Game::GameDataRef data;

    std::vector<Button> buttons;
    GuiSnake snake;

    int isOnButtonNr{};
    sf::Clock timeSinceLastClick;
    sf::Vector2i currentMousePos;
    sf::Vector2i lastMousePos;
    int signal{-1};

    const int numberOfButtons;
    const int spaceBetweenButtons;
    const float scaleFactor;
    sf::Vector2i buttonSize;
    sf::Vector2i offset;
};


}
