#include "buttonContainer.hpp"
#include <iostream>

namespace GUI
{


void ButtonContainer::update()
{
    for(auto &button : buttons)
        button.makeButtonPointed(false);

    buttons[isOnButtonNr].makeButtonPointed(true);
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


