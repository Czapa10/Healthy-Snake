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

ButtonContainer::ButtonContainer(Game::GameDataRef data, Fonts::ID fontID, std::vector<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset, bool areButtonsCentered, sf::Color fontColor)
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
                    SCREEN_WIDTH / 2 - fontSize * texts[i * areButtonsCentered].size() / centerValue + offset.x, // <- This algorithm makes problem
                    i * (1.3 * fontSize + spaceBetweenButtons) + offset.y + Hmargin
                            ),
                fontSize
            )
        );

        std::cout<<i<<"x: "<<SCREEN_WIDTH / 2 - ( fontSize * texts[i].size()) / 2 + offset.x<<std::endl;
    }

    if(fontColor != sf::Color::Black){
        for(auto &button : buttons){
            button.getText().setFillColor(fontColor);
        }
    }
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

    if(scaleFactor != 0){// if it is container for sprite buttons
        snake.update(buttons[0].getSprite().getPosition(), buttonSize, buttons[isOnButtonNr].getSprite().getPosition().y, scaleFactor);
    }
    else{// if it is container for text buttons
        snake.update(buttons[0].getText().getPosition(),
                    sf::Vector2i(buttons[0].getText().getCharacterSize() * buttons[0].getText().getString().getSize(),
                    buttons[0].getText().getCharacterSize() * 1.3),
                    buttons[isOnButtonNr].getText().getPosition().y, 1);
    }
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
            data->sound.play(Audio::Sounds::menuMove);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            --isOnButtonNr;
            if(isOnButtonNr < 0)
                isOnButtonNr = numberOfButtons - 1;
            timeSinceLastClick.restart();
            data->sound.play(Audio::Sounds::menuMove);
        }
    }

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))&&(timeSinceLastClick.getElapsedTime().asSeconds() > 0.23)){
        signal = isOnButtonNr;
        data->sound.play(Audio::Sounds::buttonClick);
    }
}

void ButtonContainer::mouseControls()
{
    currentMousePos = sf::Mouse::getPosition(data->window);

    if(currentMousePos != lastMousePos){
        for(int i = 0; i < numberOfButtons; ++i){
            if(buttons[i].isMouseOnButton(currentMousePos))
                isOnButtonNr = i;
        }

        if(isOnButtonNr != previousIsOnButtonNr)
            data->sound.play(Audio::Sounds::menuMove);

    }

    for(auto button : buttons){
        if((button.isClicked(currentMousePos))&&(timeSinceLastClick.getElapsedTime().asSeconds() > 0.23)){
            signal = isOnButtonNr;
            data->sound.play(Audio::Sounds::buttonClick);
        }
    }

    lastMousePos = currentMousePos;
    previousIsOnButtonNr = isOnButtonNr;
}


}


