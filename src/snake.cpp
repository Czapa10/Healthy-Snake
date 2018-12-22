#include "snake.hpp"

namespace GameElements
{


BodyPart::BodyPart(sf::Vector2i _pos, Direction _direction, Sprite _sprite)
:pos(_pos)
,direction(_direction)
,sprite(_sprite)
{
}

Snake::Snake()
{
    BodyPart head(sf::Vector2i(12,10), BodyPart::left, BodyPart::head);
    bodyParts.push_back(head);

    BodyPart middle(sf::Vector2i(13,10), BodyPart::left, BodyPart::straightBody);
    bodyParts.push_back(middle);

    BodyPart tail(sf::Vector2i(14,10), BodyPart::left, BodyPart::tail);
    bodyParts.push_back(tail);
}

void Snake::move()
{

}

void Snake::eat()
{

}

void Snake::grow()
{

}


}
