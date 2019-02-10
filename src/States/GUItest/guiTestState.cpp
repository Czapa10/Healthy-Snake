#include "guiTestState.hpp"

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
,buttons( data, Textures::menuButtons, 5, 10, sf::Vector2i(60, 15) )
,but(data->textures.get(Textures::menuButtons), sf::Vector2f(100.f, 100.f), sf::IntRect(0,0,60,15), sf::IntRect(0,0,60,15))
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
    data->window.clear();

    buttons.display();
    but.display(data->window);
}


}
