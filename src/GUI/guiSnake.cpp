#include "guiSnake.hpp"

namespace GUI
{


GuiSnake::GuiSnake(Game::GameDataRef data, float scale, int pillarDistanceFromButtons, unsigned int headOverFirstButton)
:data(data)
,head(data->textures.get(Textures::snakeHead8x8))
,verticalStraightBody(data->textures.get(Textures::snakeStraightBody))
,turnBody(data->textures.get(Textures::snakeTurnBody))
,horizontalStraightBody(data->textures.get(Textures::snakeStraightBody))
,pillarDistanceFromButtons(pillarDistanceFromButtons)
,headOverFirstButton(headOverFirstButton)
{
    head.scale(scale / 2, scale / 2);
    verticalStraightBody.scale(scale / 2, scale / 2);
    turnBody.scale(scale / 2, scale / 2);

    horizontalStraightBody.setOrigin(16.f, 16.f);
    horizontalStraightBody.rotate(90.f);
    horizontalStraightBody.scale(scale / 2, scale / 2);
}

void GuiSnake::init(const sf::Vector2f& posOfFirstButton, sf::Vector2i& buttonSize)
{
    head.setPosition(posOfFirstButton.x + pillarDistanceFromButtons + buttonSize.x, posOfFirstButton.y - headOverFirstButton);
}

void GuiSnake::update(sf::Vector2f posOfPointedButton)
{

}

void GuiSnake::display()
{
    data->window.draw(head);
}


}
