#include "buttonContainer.hpp"
#include <iostream>

namespace GUI
{


ButtonContainer::ButtonContainer(Game::GameDataRef data, Textures::ID textureID, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2i offset)
:data(data)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,buttonSize(buttonSize)
,offset(offset)
{
    buttons.reserve(numberOfButtons);

    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            Button(
                data,
                textureID,
                sf::Vector2f( (SCREEN_WIDTH - buttonSize.x) / 2 + offset.x, i * (buttonSize.y + spaceBetweenButtons) + offset.y ),
                sf::IntRect(0, buttonSize.y * i, buttonSize.x, buttonSize.y),
                sf::IntRect(buttonSize.x, buttonSize.y * i, buttonSize.x, buttonSize.y)
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

    std::cout<<"buttons.size() = "<<buttons.size()<<std::endl;

    return buttons[numberOfButton];
}


}
