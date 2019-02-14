#include "guiSnake.hpp"

namespace GUI
{


GuiSnake::GuiSnake(Game::GameDataRef data, float scale, int pillarDistanceFromButtons, int headOverFirstButton)
:data(data)
,head(data->textures.get(Textures::snakeHead))
,verticalStraightBody(data->textures.get(Textures::snakeStraightBody))
,turnBody(data->textures.get(Textures::snakeTurnBody))
,horizontalStraightBody(data->textures.get(Textures::snakeStraightBody))
{
    head.scale(scale, scale);
    verticalStraightBody.scale(scale, scale);
    turnBody.scale(scale, scale);

    horizontalStraightBody.setOrigin(16.f, 16.f);
    horizontalStraightBody.rotate(90.f);
    horizontalStraightBody.scale(scale, scale);

    head.setPosition(400.f, 100.f);
}

void GuiSnake::update(sf::Vector2f posOfPointedButton)
{

}

void GuiSnake::display()
{
    data->window.draw(head);
}


}
