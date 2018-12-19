#pragma once

#include <SFML/Graphics.hpp>

namespace Input
{


class MouseInput
{
public:
    MouseInput(){}
    ~MouseInput(){}

    bool isClicked(sf::Sprite, sf::RenderWindow&);
    bool isClicked(sf::IntRect, sf::RenderWindow&);
    bool isUnderMouse(sf::Sprite, sf::RenderWindow&);
    bool isUnderMouse(sf::IntRect, sf::RenderWindow&);
};


}
