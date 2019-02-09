#include "guiTestState.hpp"

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
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
}


}
