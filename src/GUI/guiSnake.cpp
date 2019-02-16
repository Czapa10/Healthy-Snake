#include "guiSnake.hpp"

#include <iostream>

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

    turnBody.setOrigin(16.f, 16.f);
    turnBody.rotate(-90.f);
    turnBody.setOrigin(0.f, 0.f);
    turnBody.scale(scale / 2, scale / 2);


    horizontalStraightBody.setOrigin(16.f, 16.f);
    horizontalStraightBody.rotate(90.f);
    horizontalStraightBody.scale(scale / 2, scale / 2);
}

void GuiSnake::setSnakePos(const sf::Vector2f& posOfFirstButton, sf::Vector2i& buttonSize, float currentButtonY, float scaleFactor)
{
    head.setPosition(posOfFirstButton.x + buttonSize.x + pillarDistanceFromButtons, posOfFirstButton.y - headOverFirstButton);
    turnBody.setPosition(head.getPosition().x, currentButtonY + buttonSize.y * scaleFactor);
    verticalStraightBody.setPosition(head.getPosition().x, head.getPosition().y + head.getTexture()->getSize().y * head.getScale().y);
    verticalStraightBody.setScale(verticalStraightBody.getScale().x, 100.f/*(head.getPosition().y + head.getTexture()->getSize().y * head.getScale().y - turnBody.getPosition().y) / verticalStraightBody.getTexture()->getSize().y * verticalStraightBody.getScale().y*/ );
}

void GuiSnake::update(sf::Vector2f posOfPointedButton)
{

}

void GuiSnake::display()
{
    data->window.draw(verticalStraightBody);
    data->window.draw(turnBody);
    data->window.draw(head);
}


}
