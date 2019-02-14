#pragma once

#include <game.hpp>

namespace GUI
{


class GuiSnake
{
public:
    GuiSnake(Game::GameDataRef data, float scale, int pillarDistanceFromButtons = 200, int headOverFirstButton = 60);

    void update(sf::Vector2f posOfPointedButton);
    void display();

private:
    Game::GameDataRef data;

    sf::Sprite head;
    sf::Sprite verticalStraightBody;
    sf::Sprite turnBody;
    sf::Sprite horizontalStraightBody;
};


}
