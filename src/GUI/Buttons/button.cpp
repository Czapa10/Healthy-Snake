#include "button.hpp"

#include <GUI/MouseInput/mouseInput.hpp>
#include <Resources/resourceIdentifiers.hpp>

namespace GUI
{




Button::Button(Game::GameDataRef data, const Fonts::ID& fontID, const std::string& content, sf::Vector2f pos, unsigned int fontSize, bool isActive)
:Button{data, fontID, content, pos, sf::Vector2i(0.f,0.f), fontSize, isActive}
{
}

Button::Button(Game::GameDataRef data, const Fonts::ID& fontID, const std::string& content, sf::Vector2f pos, sf::Vector2i clickBoxExpand, unsigned int fontSize, bool isActive)
:data(data)
,text( content, data->fonts.get(fontID), fontSize )
,notPointedRect(sf::IntRect())
,pointedRect(sf::IntRect())
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
,type(ButtonType::textButton)
{
    text.setPosition(pos);
}




}
