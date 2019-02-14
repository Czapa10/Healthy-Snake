#pragma once

#include <game.hpp>

namespace GUI
{


class GuiSnake
{
public:
    GuiSnake(Game::GameDataRef data, float scale, int pillarDistanceFromButtons = 300, unsigned int headOverFirstButton = 100);
    void init(const sf::Vector2f& posOfFirstButton, sf::Vector2i& buttonSize);

    void update(sf::Vector2f posOfPointedButton);
    void display();

private:
    Game::GameDataRef data;

    sf::Sprite head;
    sf::Sprite verticalStraightBody;
    sf::Sprite turnBody;
    sf::Sprite horizontalStraightBody;

    int pillarDistanceFromButtons;
    int headOverFirstButton;
};


}
