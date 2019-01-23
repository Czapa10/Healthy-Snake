#pragma once

#include <SFML/Graphics.hpp>

namespace Input
{


class MouseInput
{
public:
    MouseInput(){}
    ~MouseInput(){}

    bool isClicked(sf::Sprite, sf::RenderWindow&) const;
    bool isClicked(sf::IntRect, sf::RenderWindow&) const;
    bool isUnderMouse(sf::Sprite, sf::RenderWindow&) const;
    bool isUnderMouse(sf::IntRect, sf::RenderWindow&) const;
};


}