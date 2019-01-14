#include "statBar.hpp"

namespace GameElements
{


StatBar::StatBar(Game::GameDataRef _data) : data(_data)
,pointsDisplayer(data, 92, 0)
,snakeLengthDisplayer(data, 325, 0)
,inStomachDisplayer(data, 515, 0)
{
    barBackground.setTexture(data->textures.get(Textures::statisticsBar));
    barBackground.setPosition(0, 5);
}

void StatBar::draw(int points, int snakeLength, int inStomach) const
{
    data->window.draw(barBackground);

    pointsDisplayer.display(points);
    snakeLengthDisplayer.display(snakeLength);
    inStomachDisplayer.display(inStomach);
}


}
