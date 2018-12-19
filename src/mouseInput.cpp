#include "mouseInput.hpp"

namespace Input
{


bool MouseInput::isClicked(sf::Sprite sprite, sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        if(button.contains(sf::Mouse::getPosition(window))){
            return true;
        }
    }
    return false;
}

bool MouseInput::isClicked(sf::IntRect button, sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        if(button.contains(sf::Mouse::getPosition(window))){
            return true;
        }
    }
    return false;
}

bool MouseInput::isUnderMouse(sf::Sprite sprite, sf::RenderWindow &window)
{
    sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    if(button.contains(sf::Mouse::getPosition(window))){
        return true;
    }
    return false;
}

bool MouseInput::isUnderMouse(sf::IntRect button, sf::RenderWindow &window)
{
    if(button.contains(sf::Mouse::getPosition(window))){
        return true;
    }
    return false;
}


}
