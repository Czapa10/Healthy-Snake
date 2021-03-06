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
    ButtonContainer(Game::GameDataRef data, Fonts::ID, std::vector<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset = sf::Vector2i(0,0), bool areButtonsCentered = true, sf::Color fontColor = sf::Color::White);

    void input();
    void update();
    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button
    int& getSignal(){return signal;}
    void resetSignal(){signal = -1;}
    GuiSnake& getSnake(){return snake;}

private:
    void keyboardControls();
    void mouseControls();

protected:
    Game::GameDataRef data;

private:
    std::vector<Button> buttons;
    GuiSnake snake;

    int isOnButtonNr{};
    int previousIsOnButtonNr{};
    sf::Clock timeSinceLastClick;
    sf::Vector2i currentMousePos;
    sf::Vector2i lastMousePos;
    int signal{-1};

    const int numberOfButtons;
    const int spaceBetweenButtons;
    const unsigned int fontSize;
    const float scaleFactor;
    sf::Vector2i buttonSize;
    sf::Vector2i offset;
};


}
