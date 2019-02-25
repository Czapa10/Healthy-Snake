#include "guiTestState.hpp"
#include <States/Menu/menuState.hpp>
#include <iostream>
#include <string>

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
,buttons( data, Fonts::pooh, {"Play", "settings", "food stats", "credits", "exit"}, 5, 30, 30, sf::Vector2i(0, 80) )
,button( data, Fonts::pooh, "example", sf::Vector2f(30.f, 100.f) )
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

    button.display();
    //buttons.display();
}


}
