#pragma once

#include <SFML/Graphics.hpp>

namespace GameElements
{


enum class Number{_0, _1, _2, _3, _4, _5, _6, _7, _8, _9};

class NumberDisplayer
{
public:
    void display();
    void setPos(int _x, int _y);

private:
    int x;
    int y;
};


}
