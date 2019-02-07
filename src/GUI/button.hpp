#pragma once

#include <SFML/Graphics.hpp>

#include "mouseInput.hpp"

namespace GUI
{


class Button// : private MouseInput
{
public:
    Button(const sf::Texture&, sf::IntRect notPointedRect, sf::IntRect pointedRect, bool isActive = true);
    Button(const sf::Texture&, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, bool isActive = true);

    ///sf::Sprite getCurrentSprite();

private:
    enum class ButtonState{ notPointed, pointed};

private:
    const bool isActive;
    ButtonState buttonState;

    sf::IntRect notPointedRect;
    sf::IntRect pointedRect;
    sf::Sprite sprite;
    sf::Vector2i clickBoxExpand;
};


}
//rozszerzalnosc hit box-a przycisku - w pionie, w poziomie, w obu na raz
//polaczenie z inputem myszy
