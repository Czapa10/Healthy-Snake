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
            Button aux(
                data->textures.get(texture),
                sf::Vector2f( (SCREEN_WIDTH - buttonSize.x + offset.x) / 2, i * (buttonSize.y + spaceBetweenButtons) ),
                sf::IntRect(0,0 + buttonSize.y * i, buttonSize.x, buttonSize.y),
                sf::IntRect(buttonSize.x, 0 + buttonSize.y * i, buttonSize.x, buttonSize.y)
            );

            buttons.emplace_back(aux);
        }
    }
}


}
