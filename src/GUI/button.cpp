#include "button.hpp"

namespace GUI
{


Button::Button(const sf::Texture& texture, sf::IntRect notPointedRect, sf::IntRect pointedRect, bool isActive)
:Button{texture, notPointedRect, pointedRect, sf::Vector2i(0,0), isActive}
{
}

Button::Button(const sf::Texture& texture, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, bool isActive)
:sprite(texture, notPointedRect)
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
{
}


}
