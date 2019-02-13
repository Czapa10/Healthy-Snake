#include "buttonContainer.hpp"
#include <iostream>

namespace GUI
{


ButtonContainer::ButtonContainer(Game::GameDataRef data, Textures::ID textureID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2f scaleFactor, sf::Vector2i offset)
:data(data)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,buttonSize(buttonSize)
,offset(offset)
{
    buttons.reserve(numberOfButtons);

    int Hmargin = (SCREEN_HEIGHT - (scaleFactor.y * numberOfButtons * buttonSize.y + (numberOfButtons - 1) * spaceBetweenButtons) ) / 2;

    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            Button(
                data,
                textureID,
                sf::Vector2f(
                    SCREEN_WIDTH / 2 - (scaleFactor.x * buttonSize.x) / 2 + offset.x,
                    i * (scaleFactor.y * buttonSize.y + spaceBetweenButtons) + offset.y + Hmargin
                            ),
                sf::IntRect(0, buttonSize.y * i, buttonSize.x, buttonSize.y),
                sf::IntRect(buttonSize.x, buttonSize.y * i, buttonSize.x, buttonSize.y),
                scaleFactor
            )
        );
    }
}

void ButtonContainer::display()
{
    for(auto &button : buttons){
        button.display();
    }
}

Button& ButtonContainer::operator[](unsigned int numberOfButton)
{
    if(numberOfButton >= buttons.size()){
        std::cout<<"This button container has "<<buttons.size()<<" buttons ( 0 - "<<buttons.size() - 1<<
        ") So you can't get reference to "<<numberOfButton<<std::endl;
    }

    return buttons[numberOfButton];
}

void ButtonContainer::input()
{
    if(timeSinceLastClick.getElapsedTime().asSeconds() > 0.17){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            ++isOnButtonNr;
            if(isOnButtonNr == numberOfButtons)
                isOnButtonNr = 0;
            timeSinceLastClick.restart();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            --isOnButtonNr;
            if(isOnButtonNr < 0)
                isOnButtonNr = numberOfButtons - 1;
            timeSinceLastClick.restart();
        }
    }
}

void ButtonContainer::update()
{
    for(auto &button : buttons)
        button.makeButtonPointed(false);

    buttons[isOnButtonNr].makeButtonPointed(true);
}
