#include "buttonContainer.hpp"
#include <iostream>

namespace GUI
{


ButtonContainer::ButtonContainer(Game::GameDataRef data, int numberOfButtons, int spaceBetweenButtons, const sf::Vector2i& offset)
:data(data)
,isOnButtonNr(0)
,timeSinceLastClick()
,currentMousePos(sf::Vector2i())
,lastMousePos(sf::Vector2i())
,signal(-1)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,offset(offset)
{
}

void ButtonContainer::keyboardControls()
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

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))&&(timeSinceLastClick.getElapsedTime().asSeconds() > 0.23))
        signal = isOnButtonNr;
}


}


