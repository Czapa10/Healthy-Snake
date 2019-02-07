#include "button.hpp"

namespace GUI
{


Button(const sf::Texture& texture, sf::IntRect notPointedRect, sf::IntRect pointedRect, bool isActive = true)
:isActive(isActive)
,sprite(texture, notPointedRect),
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
{
}


}
