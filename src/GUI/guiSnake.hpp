#pragma once

#include <game.hpp>

namespace GUI
{


class GuiSnake
{
public:
    GuiSnake(Game::GameDataRef data, float scale, int pillarDistanceFromButtons = 300, unsigned int headOverFirstButton = 120);

    void update(const sf::Vector2f& posOfFirstButton, sf::Vector2i& buttonSize, float currentButtonY, float scaleFactor);
    void display();

    void setIsShowing(bool isShowing){this->isShowing = isShowing;}
    void setSnakePos(int pillarDistanceFromButtons, unsigned int headOverFirstButton){this->pillarDistanceFromButtons = pillarDistanceFromButtons; this->headOverFirstButton = headOverFirstButton;}

private:
    Game::GameDataRef data;

    sf::Sprite head;
    sf::Sprite verticalStraightBody;
    sf::Sprite turnBody;
    sf::Sprite horizontalStraightBody;

    bool isShowing = true;
    int pillarDistanceFromButtons;
    unsigned int headOverFirstButton;
};


}
