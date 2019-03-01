#include "mouseInput.hpp"

#include <iostream>

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
    std::cout<<"isUnderMouse 1"<<std::endl;
    return (button.contains(sf::Mouse::getPosition(window)));
    std::cout<<"isUnderMouse 2"<<std::endl;
}

bool isUnderMouse(sf::IntRect button, sf::RenderWindow &window)
{
    return (button.contains(sf::Mouse::getPosition(window)));
}


}

}
