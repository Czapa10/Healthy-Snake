#include "button.hpp"

#include "mouseInput.hpp"

namespace GUI
{


Button::Button(Game::GameDataRef data, const Textures::ID& textureID, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2f scaleFactor, bool isActive)
:Button{data, textureID, pos, notPointedRect, pointedRect, sf::Vector2i(0.f,0.f), scaleFactor, isActive}
{
}

Button::Button(Game::GameDataRef data, const Textures::ID& textureID, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, sf::Vector2f scaleFactor, bool isActive)
:data(data)
,sprite(data->textures.get(textureID), notPointedRect)
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
,clickBoxExpand(clickBoxExpand)
,isActive(isActive)
{
    sprite.setPosition(pos);
    sprite.scale(scaleFactor);
}

void Button::update()
{

}

void Button::display()
{
    data->window.draw(sprite);
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


}
