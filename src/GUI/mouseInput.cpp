#include "mouseInput.hpp"

namespace GUI
{

namespace MouseInput
{

bool isClicked(const sf::Sprite& sprite, const sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::IntRect rect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        return (rect.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool isClicked(const sf::Text& text, const sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getCharacterSize() * text.getString().getSize(), text.getCharacterSize() * text.getString().getSize() * 1.3);

        return (rect.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool isClicked(const sf::IntRect& button, const sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        return (button.contains(sf::Mouse::getPosition(window)));
    }
    return false;
}

bool isUnderMouse(const sf::Sprite& sprite, const sf::RenderWindow &window)
{
    sf::IntRect rect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    return (rect.contains(sf::Mouse::getPosition(window)));
}

bool isUnderMouse(const sf::Text& text, const sf::RenderWindow &window)
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getCharacterSize() * text.getString().getSize(), text.getCharacterSize() * text.getString().getSize() * 1.3);

    return (rect.contains(sf::Mouse::getPosition(window)));
}

bool isUnderMouse(const sf::IntRect& button, const sf::RenderWindow &window)
{
    return (button.contains(sf::Mouse::getPosition(window)));
}


}

}
