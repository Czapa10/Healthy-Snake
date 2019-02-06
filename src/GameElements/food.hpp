#pragma once

#include <SFML/Graphics.hpp>

#include <Resources/resourceIdentifiers.hpp>

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
        chicken,
        iceCream,
        donut,
        frites
    };

    Food();
    void setType();

    void setRandomPos();
    void setPos(const sf::Vector2i& _pos);
    int getWeight() const;
    int getPoints() const;//NutritionalValue

    Textures::ID getTextureID() const;
    sf::Vector2i getPosition(){return pos;}

private:
    Type type;
    sf::Vector2i pos;
};


}
