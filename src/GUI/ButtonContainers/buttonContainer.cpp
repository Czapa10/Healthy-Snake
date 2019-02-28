#include "buttonContainer.hpp"
#include <iostream>

namespace GUI
{


ButtonContainer::ButtonContainer(Game::GameDataRef data, Fonts::ID fontID, std::vector<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset, bool areButtonsCentered)
:data(data)
,snake(data, 4u)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,offset(offset)
,fontSize(fontSize)
,scaleFactor(0)
{
    buttons.reserve(numberOfButtons);

    int Hmargin = (SCREEN_HEIGHT - (1.3 * fontSize * numberOfButtons + (numberOfButtons - 1) * spaceBetweenButtons) ) / 2;

    int centerValue = areButtonsCentered ? 4 : 2;

    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            Button(
                data,
                fontID,
                texts[i],
                sf::Vector2f(
                    SCREEN_WIDTH / 2 - fontSize * texts[i].size() / centerValue + offset.x, // <- This algorithm makes problem
                    i * (1.3 * fontSize + spaceBetweenButtons) + offset.y + Hmargin
                            ),
                fontSize
            )
        );

        std::cout<<i<<"x: "<<SCREEN_WIDTH / 2 - ( fontSize * texts[i].size()) / 2 + offset.x<<std::endl;
    }


}

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


