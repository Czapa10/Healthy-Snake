#include "statBar.hpp"

namespace GameElements
{


StatBar::StatBar(Game::GameDataRef _data) : data(_data)
{
    pointsDisplayer.setPos(100, 0);
    snakeLengthDisplayer.setPos(200, 0);
    inStomachDisplayer.setPos(300, 0);

    barBackground.setTexture(data->textures.get(Textures::statisticsBar));
}

void StatBar::draw(int points, int snakeLength, int inStomach)
{
    data->window.draw(barBackground);
}


}
