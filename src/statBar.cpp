#include "statBar.hpp"

namespace GameElements
{


StatBar::StatBar(sf::Texture & barBackgroundTexture)
{
    pointsDisplayer.setPos(100, 0);
    snakeLengthDisplayer.setPos(200, 0);
    inStomachDisplayer.setPos(300, 0);

    barBackground.setTexture(barBackgroundTexture);
}

void StatBar::draw(int points, int snakeLength, int inStomach, sf::RenderWindow & window)
{
    window.draw(barBackground);
}


}
