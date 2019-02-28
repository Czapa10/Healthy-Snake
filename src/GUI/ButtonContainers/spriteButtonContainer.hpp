#pragma once

#include "buttonContainer.hpp"

namespace GUI
{


class SpriteButtonContainer : public ButtonContainer
{
public:
    SpriteButtonContainer();

    void input();
    void update();
    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button

private:
    void mouseControls();

private:
    std::vector<SpriteButton> buttons;

    const float scaleFactor;
    sf::Vector2i buttonSize;
};


}
