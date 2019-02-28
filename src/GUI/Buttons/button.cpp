#include "button.hpp"

#include <GUI/MouseInput/mouseInput.hpp>
#include <Resources/resourceIdentifiers.hpp>

namespace GUI
{


Button::Button(Game::GameDataRef, const sf::Vector2i& clickBoxExpand, const bool& isActive)
:data(data)
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
{
}


}
