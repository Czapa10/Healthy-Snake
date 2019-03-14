#pragma once

#include <SFML/Graphics.hpp>

namespace GUI
{


namespace MouseInput
{
    bool isClicked(const sf::Sprite&, const sf::RenderWindow&);
    bool isClicked(const sf::Text&, const sf::RenderWindow&);
    bool isClicked(const sf::IntRect&, const sf::RenderWindow&);
    bool isUnderMouse(const sf::Sprite&, const sf::RenderWindow&);
    bool isUnderMouse(const sf::Text&, const sf::RenderWindow&);
    bool isUnderMouse(const sf::IntRect&, const sf::RenderWindow&);
}


}
