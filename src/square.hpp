#pragma once

#include <SFML/Graphics.hpp>

#include "resourceIdentifiers.hpp"

namespace GameElements
{


class Square
{
public:
    void setID(Textures::ID);
    sf::Sprite getSprite();

private:
    Textures::ID graphicsID;
    sf::Sprite sprite;
};


}
