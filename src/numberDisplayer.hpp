#pragma once

namespace GameElements
{


enum class Number{_0, _1, _2, _3, _4, _5, _6, _7, _8, _9};

class NumberDisplayer
{
public:
    NumberDisplayer();
    void display();

private:
    sf::Vector2i pos;
};


}
