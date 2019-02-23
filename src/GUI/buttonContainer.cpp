#include "buttonContainer.hpp"
#include <iostream>

namespace GUI
{


ButtonContainer::ButtonContainer(Game::GameDataRef data, Textures::ID textureID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, float scaleFactor, sf::Vector2i offset)
:data(data)
,snake(data, scaleFactor)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,buttonSize(buttonSize)
,offset(offset)
,scaleFactor(scaleFactor)
,fontSize(0)
{
    buttons.reserve(numberOfButtons);

    int Hmargin = (SCREEN_HEIGHT - (scaleFactor * numberOfButtons * buttonSize.y + (numberOfButtons - 1) * spaceBetweenButtons) ) / 2;

    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            Button(
                data,
                textureID,
                sf::Vector2f(
                    SCREEN_WIDTH / 2 - (scaleFactor * buttonSize.x) / 2 + offset.x,
                    i * (scaleFactor * buttonSize.y + spaceBetweenButtons) + offset.y + Hmargin
                            ),
                sf::IntRect(0, buttonSize.y * i, buttonSize.x, buttonSize.y),
                sf::IntRect(buttonSize.x, buttonSize.y * i, buttonSize.x, buttonSize.y),
                scaleFactor
            )
        );
    }
}

ButtonContainer::ButtonContainer(Game::GameDataRef data, Fonts::ID fontID, std::initializer_list<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset)
:data(data)
,snake(data, fontSize)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,buttonSize(buttonSize)
,offset(offset)
,fontSize(fontSize)
,scaleFactor(0)
{
    buttons.reserve(numberOfButtons);

    int Hmargin = (SCREEN_HEIGHT - (scaleFactor * numberOfButtons * buttonSize.y + (numberOfButtons - 1) * spaceBetweenButtons) ) / 2;

    #if 0
    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            Button(
                data,
                fontID,
                texts[i],
                sf::Vector2f(
                    SCREEN_WIDTH / 2 - (1.3 * (fontSize / 1.7) * buttonSize.x) / 2 + offset.x,
                    i * (1.3 * fontSize * buttonSize.y + spaceBetweenButtons) + offset.y + Hmargin
                            ),
                sf::IntRect(0, buttonSize.y * i, buttonSize.x, buttonSize.y),
                sf::IntRect(buttonSize.x, buttonSize.y * i, buttonSize.x, buttonSize.y),
                fontSize
            )
        );
    }
    #endif // 0
}

void ButtonContainer::input()
{
    keyboardControls();
    mouseControls();
}

void ButtonContainer::update()
{
    for(auto &button : buttons)
        button.makeButtonPointed(false);

    buttons[isOnButtonNr].makeButtonPointed(true);

    snake.update(buttons[0].getSprite().getPosition(), buttonSize, buttons[isOnButtonNr].getSprite().getPosition().y, scaleFactor);
}

void ButtonContainer::display()
{
    snake.display();

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

void ButtonContainer::mouseControls()
{
    currentMousePos = sf::Mouse::getPosition(data->window);

    if(currentMousePos != lastMousePos){
        for(int i = 0; i < numberOfButtons; ++i){
            if(buttons[i].isMouseOnButton(currentMousePos))
                isOnButtonNr = i;
        }
    }

    for(auto button : buttons){
        if((button.isClicked(currentMousePos))&&(timeSinceLastClick.getElapsedTime().asSeconds() > 0.23))
            signal = isOnButtonNr;
    }

    lastMousePos = currentMousePos;
}


}


