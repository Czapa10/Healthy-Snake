#include "button.hpp"

#include "mouseInput.hpp"

namespace GUI
{


Button::Button(const sf::Texture& texture, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, bool isActive)
:Button{texture, pos, notPointedRect, pointedRect, sf::Vector2i(0.f,0.f), isActive}
{
}

Button::Button(const sf::Texture& texture, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, bool isActive)
:sprite(texture, notPointedRect)
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
{
    sprite.setPosition(pos);
}

void Button::update()
{

}

void display(const sf::RenderWindow &window)
{

}


}
