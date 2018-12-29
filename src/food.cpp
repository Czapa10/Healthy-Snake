#include "food.hpp"

#include <random>

namespace GameElements
{


std::mt19937 randomEngine{std::random_device{}()};

Food::Food()
{
    setType();
    setRandomPos();
}

void Food::setType()
{
    std::uniform_int_distribution<int> distr(0, 4);

    switch(distr(randomEngine)){
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
    std::uniform_int_distribution<int> x(0, 31);
    std::uniform_int_distribution<int> y(0, 23);

    pos.x = x(randomEngine);
    pos.y = y(randomEngine);
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
