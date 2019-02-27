#include "textButton.h"

#include <cctype>

namespace GUI
{


TextButton::TextButton(Game::GameDataRef data, const Fonts::ID& fontID, const std::string& content, sf::Vector2f pos, unsigned int fontSize, bool isActive)
:Button{data, fontID, content, pos, sf::Vector2i(0.f,0.f), fontSize, isActive}
{
}

TextButton::TextButton(Game::GameDataRef data, const Fonts::ID& fontID, const std::string& content, sf::Vector2f pos, sf::Vector2i clickBoxExpand, unsigned int fontSize, bool isActive)
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

void TextButton::display()
{
    data->window.draw(text);
}

void TextButton::makeButtonPointed(bool buttonIsPointed)
{
    isPointed = buttonIsPointed;

    if(isPointed == true){
        //toupper will be here
    }
    else{
        //tolower will be here
    }
}

bool TextButton::isMouseOnButton(sf::Vector2i &currentPos)
{
    return MouseInput::isUnderMouse(/*text*/, data->window);
}

bool TextButton::isClicked(sf::Vector2i &currentPos)
{
    return MouseInput::isClicked(/*text*/, data->window);
}


}
