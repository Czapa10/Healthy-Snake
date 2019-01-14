#pragma once

#include <SFML/Graphics.hpp>

#include "resourceIdentifiers.hpp"

namespace GameElements
{


class Food
{
public:
    enum Type//of food
    {
        appleRed,
        appleYellow,
        cherry,
        hamburger,
        chicken
    };

    Food();
    void setType();

    void setRandomPos();
    void setPos(sf::Vector2i _pos);
    int getWeight() const;
    int getPoints() const;//NutritionalValue

    Textures::ID getTextureID() const;
    sf::Vector2i getPosition(){return pos;}

private:
    Type type;
    sf::Vector2i pos;
};


}
