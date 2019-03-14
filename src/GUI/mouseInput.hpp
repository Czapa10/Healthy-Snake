#pragma once

#include <SFML/Graphics.hpp>

namespace GUI
{


namespace MouseInput
{
    bool isClicked(sf::Sprite, sf::RenderWindow&);
    bool isClicked(sf::Text, sf::RenderWindow&);
    bool isClicked(sf::IntRect, sf::RenderWindow&);
    bool isUnderMouse(sf::Sprite, sf::RenderWindow&);
    bool isUnderMouse(sf::Text, sf::RenderWindow&);
    bool isUnderMouse(sf::IntRect, sf::RenderWindow&);
}


}
