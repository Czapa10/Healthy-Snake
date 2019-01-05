#include "statBar.hpp"

namespace GameElements
{


StatBar::StatBar(Game::GameDataRef _data) : data(_data)
,pointsDisplayer(100, 0)
,snakeLengthDisplayer(200, 0)
,inStomachDisplayer(300, 0)
{
    barBackground.setTexture(data->textures.get(Textures::statisticsBar));
}

void StatBar::draw(int points, int snakeLength, int inStomach)
{
    data->window.draw(barBackground);
}


}
