#pragma once

#include "buttonContainer.hpp"
#include <GUI/Buttons/spriteButton.hpp>

namespace GUI
{


class SpriteButtonContainer : public ButtonContainer
{
public:
    SpriteButtonContainer(Game::GameDataRef data, Textures::ID&, int& numberOfButtons, int& spaceBetweenButtons, sf::Vector2i& buttonSize, float& scaleFactor = 4, sf::Vector2i& offset = sf::Vector2i(0,0));

    void input();
    void update();
    void display();
    Button& operator[](unsigned int numberOfButton); //access to certain button
    GuiSnake& getSnake(){return snake;}

private:
    void mouseControls();

private:
    std::vector<SpriteButton> buttons;

    GUI::GuiSnake snake;

    const float scaleFactor;
    sf::Vector2i buttonSize;
};


}
