#include "spriteButtonContainer.hpp"

namespace GUI
{


SpriteButtonContainer::SpriteButtonContainer(Game::GameDataRef data, Textures::ID textureID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, float scaleFactor, sf::Vector2i offset)
:ButtonContainer(data, numberOfButtons, spaceBetweenButtons, offset)
,snake(data, scaleFactor)
,buttonSize(buttonSize)
,scaleFactor(scaleFactor)
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

void SpriteButtonContainer::input()
{
    keyboardControls();
    mouseControls();
}

void SpriteButtonContainer::update()
{
    ButtonContainer::update();
    snake.update(buttons[0].getSprite().getPosition(), buttonSize, buttons[isOnButtonNr].getSprite().getPosition().y, scaleFactor);
}

void SpriteButtonContainer::display()
{
    snake.display();

    for(auto &button : buttons){
        button.display();
    }
}

SpriteButton& SpriteButtonContainer::operator[](unsigned int numberOfButton)
{
    if(numberOfButton >= buttons.size()){
        std::cout<<"This button container has "<<buttons.size()<<" buttons ( 0 - "<<buttons.size() - 1<<
        ") So you can't get reference to "<<numberOfButton<<std::endl;
    }
    return;

    return buttons[numberOfButton];
}

void SpriteButtonContainer::mouseControls()
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
