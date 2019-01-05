#include "statBar.hpp"

#include <iostream>

namespace GameElements
{


StatBar::StatBar(Game::GameDataRef _data) : data(_data)
,pointsDisplayer(data, 120, 0)
,snakeLengthDisplayer(data, 460, 0)
,inStomachDisplayer(data, 760, 0)
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
