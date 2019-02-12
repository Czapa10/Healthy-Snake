#include "guiTestState.hpp"

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
,buttons( data, Textures::menuButtons, 5, 50, sf::Vector2i(60, 15), sf::Vector2f(5.f, 5.f) )
{
}

void GuiTestState::input()
{

}

void GuiTestState::update(sf::Time deltaTime)
{

}

void GuiTestState::draw()
{
    data->window.clear(sf::Color::White);

    buttons.display();
}


}
