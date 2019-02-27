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
    horizontalStraightBody.setOrigin(0.f, 0.f);
}

GuiSnake::GuiSnake(Game::GameDataRef data, unsigned int fontSize, int pillarDistanceFromButtons, unsigned int headOverFirstButton)
:GuiSnake{data, static_cast<float>(fontSize), pillarDistanceFromButtons, headOverFirstButton}
{
}

void GuiSnake::update(const sf::Vector2f& posOfFirstButton, sf::Vector2i& buttonSize, float currentButtonY, float scaleFactor)
{
    head.setPosition(posOfFirstButton.x + buttonSize.x + pillarDistanceFromButtons, posOfFirstButton.y - headOverFirstButton);

    turnBody.setPosition(head.getPosition().x, currentButtonY + buttonSize.y * scaleFactor);

    verticalStraightBody.setPosition(head.getPosition().x, head.getPosition().y + (head.getTexture()->getSize().y * head.getScale().y / 2) );
    verticalStraightBody.setScale(verticalStraightBody.getScale().x, ((turnBody.getPosition().y) - (head.getPosition().y + head.getTexture()->getSize().y * head.getScale().y)) / 32 );

    horizontalStraightBody.setPosition(turnBody.getPosition().x, turnBody.getPosition().y - turnBody.getTexture()->getSize().y * turnBody.getScale().y);
    horizontalStraightBody.setScale(horizontalStraightBody.getScale().x, 50.f);
}

void GuiSnake::display()
{
    if(!isShowing)
        return;

    data->window.draw(verticalStraightBody);
    data->window.draw(horizontalStraightBody);
    data->window.draw(turnBody);
    data->window.draw(head);
}


}
