#pragma once

#include <SFML/Graphics.hpp>

namespace GUI
{


class Button
{
public:
    Button(const sf::Texture&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, bool isActive = true);
    Button(const sf::Texture&, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, bool isActive = true);

    void update();
    void display(const sf::RenderWindow &window);

private:
    enum class ButtonState{ notPointed, pointed};

private:
    const bool isActive;
    ButtonState buttonState {ButtonState::notPointed};

    sf::IntRect notPointedRect;
    sf::IntRect pointedRect;
    sf::Sprite sprite;
    sf::Vector2i clickBoxExpand;
};


}
