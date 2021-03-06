#include "numberDisplayer.hpp"

namespace GameElements
{


NumberDisplayer::NumberDisplayer(Game::GameDataRef data, int x, int y) : data(data)
,x(x)
,y(y)
{
}

void NumberDisplayer::display(int toDisplay) const
{
    std::vector<int> digint;

    if(toDisplay < 0){
        toDisplay = -toDisplay;

        sf::Sprite minus(data->textures.get(Textures::minus));
        minus.setPosition(x - 15, y + 11);
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
        dSprite.setPosition(x + i * 24, y);
        dSprite.setTextureRect(sf::IntRect(digint[i] * 24, 0, 24, 30));

        data->window.draw(dSprite);

        ++i;
    }
}


}
