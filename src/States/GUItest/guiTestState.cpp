#include "guiTestState.hpp"

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
,buttons( data, Textures::menuButtons, 5, 30, sf::Vector2i(60, 15), sf::Vector2f(5.f, 5.f) )
{
}

void GuiTestState::input()
{
    buttons.input();
}

void GuiTestState::update(sf::Time deltaTime)
{
    buttons.update();
}

void GuiTestState::draw()
{
    data->window.clear(sf::Color::White);

    buttons.display();
}


}
