#include "statBar.hpp"

#include <iostream>

namespace GameElements
{


StatBar::StatBar(Game::GameDataRef _data) : data(_data)
,pointsDisplayer(data, 135, 0)
,snakeLengthDisplayer(data, 475, 0)
,inStomachDisplayer(data, 775, 0)
{
    barBackground.setTexture(data->textures.get(Textures::statisticsBar));
}

void StatBar::draw(int points, int snakeLength, int inStomach)
{
    data->window.draw(barBackground);

    pointsDisplayer.display(points);
    snakeLengthDisplayer.display(snakeLength);
    inStomachDisplayer.display(inStomach);
}


}
