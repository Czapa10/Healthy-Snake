#include "guiTestState.hpp"
#include <States/Menu/menuState.hpp>
#include <iostream>

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
,buttons( data, Textures::menuButtons, 5, 30, sf::Vector2i(60, 15), 5, sf::Vector2i(0, 80) )
{
}

void GuiTestState::input()
{
    buttons.input();
}

void GuiTestState::update(sf::Time deltaTime)
{
    buttons.update();

    switch(buttons.getSignal()){
        case 0:
            std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
            data->stateStack.pushState(std::move(toStack));
            break;
    }
}

void GuiTestState::draw()
{
    data->window.clear(sf::Color::White);

    buttons.display();
}


}
