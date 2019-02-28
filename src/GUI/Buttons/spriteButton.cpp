#include "spriteButton.hpp"

namespace GUI
{


SpriteButton::SpriteButton(Game::GameDataRef data, const Textures::ID& textureID, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, float scaleFactor, bool isActive)
:SpriteButton{data, textureID, pos, notPointedRect, pointedRect, sf::Vector2i(0.f,0.f), scaleFactor, isActive}
{
}

SpriteButton::SpriteButton(Game::GameDataRef data, const Textures::ID& textureID, sf::Vector2f pos, sf::IntRect notPointedRect, sf::IntRect pointedRect, sf::Vector2i clickBoxExpand, float scaleFactor, bool isActive)
:Button(data, clickBoxExpand, isActive)
,sprite(data->textures.get(textureID), notPointedRect)
,notPointedRect(notPointedRect)
,pointedRect(pointedRect)
{
    sprite.setPosition(pos);
    sprite.scale(scaleFactor, scaleFactor);
}

void SpriteButton::display()
{
    data->window.draw(sprite);
}

void SpriteButton::makeButtonPointed(bool buttonIsPointed)
{
    isPointed = buttonIsPointed;

    if(isPointed == true){
        sprite.setTextureRect(pointedRect);
    }
    else{
        sprite.setTextureRect(notPointedRect);
    }
}

bool SpriteButton::isMouseOnButton(sf::Vector2i &currentPos)
{
    return MouseInput::isUnderMouse(sprite, data->window);
}

bool SpriteButton::isClicked(sf::Vector2i &currentPos)
{
    return MouseInput::isClicked(sprite, data->window);
}


}
