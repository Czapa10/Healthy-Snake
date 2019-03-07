#include "statBar.hpp"

namespace GameElements
{

constexpr int BAR_X = 259;

StatBar::StatBar(Game::GameDataRef _data) : data(_data)
,pointsDisplayer(data, 92 + BAR_X, 0)
,snakeLengthDisplayer(data, 325 + BAR_X, 0)
,inStomachDisplayer(data, 515 + BAR_X, 0)
{
    barBackground.setTexture(data->textures.get(Textures::statisticsBar));
    barBackground.setPosition(BAR_X, 5);
}

void StatBar::draw(int points, int snakeLength, int inStomach) const
{
    data->window.draw(barBackground);

    pointsDisplayer.display(points);
    snakeLengthDisplayer.display(snakeLength);
    inStomachDisplayer.display(inStomach);
}


}
