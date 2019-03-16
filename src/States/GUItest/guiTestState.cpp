#include "guiTestState.hpp"
#include <States/Menu/menuState.hpp>
#include <iostream>
#include <string>

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
,buttons( data, Fonts::fipps, {"Play", "settings", "food stats", "credits", "exit"}, 5, 60, 50 )
//,buttons( data, Fonts::pooh, {"Play", "settings", "food stats"}, 3, 60, 50 )
{
    buttons.getSnake().setSnakePos(200, 100);
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
    data->window.clear();

    buttons.display();
}


}
