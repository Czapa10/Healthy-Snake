#include "square.hpp"

namespace GameElements
{


void Square::setID(Textures::ID id)
{
    graphicsID = id;
}

sf::Sprite Square::getSprite()
{
    return sprite;
}


}
