#pragma once

#include <SFML/Graphics.hpp>

namespace Input
{


class InputManager
{
public:
    InputManager(){}
    ~InputManager(){}

    bool isSpriteClicked(sf::Sprite, sf::RenderWindow);
    bool isSpriteUnderMouse(sf::Sprite, sf::RenderWindow);
};


}
