#include "numberDisplayer.hpp"

#include <cstdlib>

namespace GameElements
{


NumberDisplayer::NumberDisplayer(Game::GameDataRef _data, int _x, int _y) : data(_data)
,x(_x)
,y(_y)
{
}

void NumberDisplayer::display(int toDisplay)
{
    std::vector<int> digint;

    if(toDisplay < 0){
        toDisplay = -toDisplay;

        sf::Sprite minus(data->textures.get(Textures::minus));
        minus.setPosition(x - 15, y + 21);
        data->window.draw(minus);
    }

    if(toDisplay > 999){
        digint.emplace_back(toDisplay / 1000);
        digint.emplace_back(toDisplay / 100 - digint[0] * 10);
        digint.emplace_back(toDisplay / 10 - digint[0] * 100 - digint[1] * 10);
        digint.emplace_back(toDisplay - digint[0] * 1000 - digint[1] * 100 - digint[2] * 10);
    }
    else if(toDisplay > 99){
        digint.emplace_back(toDisplay / 100);
        digint.emplace_back(toDisplay / 10 - digint[0] * 10);
        digint.emplace_back(toDisplay - digint[0] * 100 - digint[1] * 10);
    }
    else if(toDisplay > 9){
        digint.emplace_back(toDisplay / 10);
        digint.emplace_back(toDisplay - digint[0] * 10);
    }
    else{
        digint.emplace_back(toDisplay);
    }


    int i{};
    for(auto d : digint){
        sf::Sprite dSprite(data->textures.get(Textures::numbers));
        dSprite.setPosition(x + i * 30, y);
        dSprite.setTextureRect(sf::IntRect(digint[i] * 24, 0, 24, 30));

        data->window.draw(dSprite);

        ++i;
    }
}


}
