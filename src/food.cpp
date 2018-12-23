#include <time.h>

#include "food.hpp"

namespace GameElements
{


Food::Food()
{
    srand(time(NULL));

    setType();
    setRandomPos();
}

void Food::setType()
{
    int lot = rand() % 5;

    switch(lot){
        case 0:
            type = appleRed;
            break;

        case 1:
            type = appleYellow;
            break;

        case 2:
            type = cherry;
            break;

        case 3:
            type = hamburger;
            break;

        case 4:
            type = meat;
            break;
    }
}

void Food::setRandomPos()
{
    int x = rand() % 32;
    int y = rand() % 24;

    pos.x = x;
    pos.y = y;
}


void Food::setPos(sf::Vector2i _pos)
{
    pos = _pos;
}

int Food::getCaloric()
{
    switch(type){
        case appleRed:
            return 2;

        case appleYellow:
            return 2;

        case cherry:
            return 1;

        case hamburger:
            return 7;

        case meat:
            return 6;
    }
}


}
