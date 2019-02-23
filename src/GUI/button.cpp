#include "button.hpp"

#include "mouseInput.hpp"
#include <Resources/resourceIdentifiers.hpp>

namespace GUI
{


Button::Button(Game::GameDataRef data, const Textures::ID& textureID, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, float scaleFactor, bool isActive)
:Button{data, textureID, pos, notPointedRect, pointedRect, sf::Vector2i(0.f,0.f), scaleFactor, isActive}
{
}

Button::Button(Game::GameDataRef data, const Textures::ID& textureID, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, float scaleFactor, bool isActive)
:data(data)
,sprite(data->textures.get(textureID), notPointedRect)
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
,type(ButtonType::spriteButton)
{
    sprite.setPosition(pos);
    sprite.scale(scaleFactor, scaleFactor);
}

Button::Button(Game::GameDataRef data, const Fonts::ID& fontID, const std::string& content, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, unsigned int fontSize, bool isActive)
:Button{data, fontID, content, pos, notPointedRect, pointedRect, sf::Vector2i(0.f,0.f), fontSize, isActive}
{
}

Button::Button(Game::GameDataRef data, const Fonts::ID& fontID, const std::string& content, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, unsigned int fontSize, bool isActive)
:data(data)
,text( content, data->fonts.get(fontID), fontSize )
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
,type(ButtonType::textButton)
{
    text.setPosition(pos);
}

void Button::update()
{

}

void Button::display()
{
    if(type == ButtonType::spriteButton)
        data->window.draw(sprite);
    else
        data->window.draw(text);
}

void Button::makeButtonPointed(bool buttonIsPointed)
{
    isPointed = buttonIsPointed;

    if(isPointed == true){
        sprite.setTextureRect(pointedRect);
    }
    else{
        sprite.setTextureRect(notPointedRect);
    }
}

bool Button::isMouseOnButton(sf::Vector2i &currentPos)
{
    return MouseInput::isUnderMouse(sprite, data->window);
}

bool Button::isClicked(sf::Vector2i &currentPos)
{
    return MouseInput::isClicked(sprite, data->window);
}


}
