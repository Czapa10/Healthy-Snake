#include "mouseInput.hpp"

namespace GUI
{

namespace MouseInput
{

bool isClicked(sf::Sprite sprite, sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        return (button.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool isClicked(sf::Text text, sf::RenderWindow&)
{

}

bool isClicked(sf::IntRect button, sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        return (button.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool isUnderMouse(sf::Sprite sprite, sf::RenderWindow &window)
{
    sf::IntRect button(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    return (button.contains(sf::Mouse::getPosition(window)));
}

bool isUnderMouse(sf::Text text, sf::RenderWindow&)
{

}

bool isUnderMouse(sf::IntRect button, sf::RenderWindow &window)
{
    return (button.contains(sf::Mouse::getPosition(window)));
}


}

}
