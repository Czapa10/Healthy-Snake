#include "spriteButtonContainer.hpp"

namespace GUI
{


SpriteButtonContainer::SpriteButtonContainer(Game::GameDataRef data, Textures::ID textureID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, const float scaleFactor, const sf::Vector2i offset)
:ButtonContainer(data, numberOfButtons, spaceBetweenButtons, offset)
,snake(data, scaleFactor)
,buttonSize(buttonSize)
,scaleFactor(scaleFactor)
{
    buttons.reserve(numberOfButtons);

    int Hmargin = (SCREEN_HEIGHT - (scaleFactor * numberOfButtons * buttonSize.y + (numberOfButtons - 1) * spaceBetweenButtons) ) / 2;

    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            SpriteButton(
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

    std::cout<<"SpriteButtonContainer constructor"<<std::endl;
}

void SpriteButtonContainer::input()
{
    std::cout<<"SpriteButtonContainer input 1"<<std::endl;
    keyboardControls();
    std::cout<<"SpriteButtonContainer input 2"<<std::endl;
    mouseControls();
    std::cout<<"SpriteButtonContainer input 3"<<std::endl;
}

void SpriteButtonContainer::update()
{
    std::cout<<"SpriteButtonContainer update"<<std::endl;

    for(auto &button : buttons)
        button.makeButtonPointed(false);

    buttons[isOnButtonNr].makeButtonPointed(true);

    snake.update(buttons[0].getSprite().getPosition(), buttonSize, buttons[isOnButtonNr].getSprite().getPosition().y, scaleFactor);
}

void SpriteButtonContainer::display()
{
    std::cout<<"SpriteButtonContainer display"<<std::endl;

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

        int exc;
        throw exc;
    }

    return buttons[numberOfButton];
}

void SpriteButtonContainer::mouseControls()
{
    currentMousePos = sf::Mouse::getPosition(data->window);

    if(currentMousePos != lastMousePos){
        for(int i = 0; i < numberOfButtons; ++i){
            std::cout<<"SpriteButtonContainer mouse controls 1"<<std::endl;
            if(buttons[i].isMouseOnButton(currentMousePos)){
                std::cout<<"SpriteButtonContainer mouse controls 2"<<std::endl;
                isOnButtonNr = i;
            }
        }
    }



    for(auto button : buttons){
        if((button.isClicked(currentMousePos))&&(timeSinceLastClick.getElapsedTime().asSeconds() > 0.23))
            signal = isOnButtonNr;
    }

    lastMousePos = currentMousePos;
}


}
