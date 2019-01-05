#include "numberDisplayer.hpp"

#include <iostream>

namespace GameElements
{


NumberDisplayer::NumberDisplayer(Game::GameDataRef _data, int _x, int _y) : data(_data)
,x(_x)
,y(_y)
{
}

void NumberDisplayer::display(int toDisplay)
{
    std::vector<sf::Sprite> digit;
    std::vector<int> digint;

    if(toDisplay > 999){
        digint.push_back(toDisplay / 1000);
        digint.push_back(toDisplay / 100 - digint[0] * 10);
        digint.push_back(toDisplay / 10 - digint[0] * 100 - digint[1] * 10);
        digint.push_back(toDisplay - digint[0] * 1000 - digint[1] * 100 - digint[2] * 10);
    }
    else if(toDisplay > 99){
        digint.push_back(toDisplay / 100);
        digint.push_back(toDisplay / 10 - digint[0] * 10);
        digint.push_back(toDisplay - digint[0] * 100 - digint[1] * 10);
    }
    else if(toDisplay > 9){
        digint.push_back(toDisplay / 10);
        digint.push_back(toDisplay - digint[0] * 10);
    }
    else{
        digint.push_back(toDisplay);
    }

    for(auto d : digint){
        std::cout<<d;
    }
}


}
