#include "inputManager.hpp"

namespace Input
{


bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::RenderWindow window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));{
        sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        if(button.contains(sf::Mouse::getPosition(window))){
            return true;
        }
    }

    return false;
}

bool InputManager::isSpriteUnderMouse(sf::Sprite sprite, sf::RenderWindow window)
{
    sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    if(button.contains(sf::Mouse::getPosition(window))){
        return true;
    }

    return false;
}


}
