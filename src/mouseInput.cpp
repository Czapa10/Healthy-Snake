#include "mouseInput.hpp"

namespace Input
{


bool MouseInput::isClicked(sf::Sprite sprite, sf::RenderWindow &window) const
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        return (button.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool MouseInput::isClicked(sf::IntRect button, sf::RenderWindow &window) const
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        return (button.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool MouseInput::isUnderMouse(sf::Sprite sprite, sf::RenderWindow &window) const
{
    sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    return (button.contains(sf::Mouse::getPosition(window)));
}

bool MouseInput::isUnderMouse(sf::IntRect button, sf::RenderWindow &window) const
{
    return (button.contains(sf::Mouse::getPosition(window)));
}


}
