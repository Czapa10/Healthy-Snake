#include "buttonContainer.hpp"

namespace GUI
{


ButtonContainer::ButtonContainer(Game::GameDataRef data, Textures::ID texture, int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2i offset, bool symmetricSpaceBetweenButton)
:data(data)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,buttonSize(buttonSize)
,offset(offset)
,symmetricSpaceBetweenButtons(symmetricSpaceBetweenButtons)
{
    buttons.reserve(numberOfButtons);

    if(symmetricSpaceBetweenButtons){
        for(int i = 0; i < numberOfButtons; ++i){
            buttons.emplace_back(
                Button(data->textures.get(texture),
                sf::Vector2f( (SCREEN_WIDTH - buttonSize.x) / 2 + offset.x, i * (buttonSize.y + spaceBetweenButtons) + offset.y ),
                sf::IntRect(0, buttonSize.y * i, buttonSize.x, buttonSize.y),
                sf::IntRect(buttonSize.x, buttonSize.y * i, buttonSize.x, buttonSize.y))
            );
        }
    }
}

void ButtonContainer::display()
{
    for(auto &button : buttons){
        button.display(data->window);
    }
}


}
