#include "button.hpp"

#include <GUI/MouseInput/mouseInput.hpp>
#include <Resources/resourceIdentifiers.hpp>

#include <iostream>

namespace GUI
{


Button::Button(Game::GameDataRef, const sf::Vector2i& clickBoxExpand, bool isActive)
:data(data)
,clickBoxExpand(clickBoxExpand)
,isPointed(false)
,isActive(isActive)
{
}


}
