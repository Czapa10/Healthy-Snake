#pragma once

#include "buttonContainer"
#include <GUI/Buttons/textButton.hpp>

namespace GUI
{


class TextButtonContainer : public ButtonContainer
{
public:
    TextButtonContainer(Game::GameDataRef data, Fonts::ID, std::vector<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset = sf::Vector2i(0,0), bool areButtonsCentered = true);

    void input();
    void update();
    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button

private:
    void mouseControls();

private:
    std::vector<TextButton> buttons;

    const unsigned int fontSize;
};


}
