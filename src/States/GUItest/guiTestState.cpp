#include "guiTestState.hpp"
#include <States/Menu/menuState.hpp>
#include <iostream>
#include <string>

#include <Resources/resourceIdentifiers.hpp>

namespace States
{


GuiTestState::GuiTestState(Game::GameDataRef data) : data(data)
//,button(data, Textures::menuButtons, sf::Vector2f(100.f, 100.f), sf::IntRect(0, 0, 60, 16), sf::IntRect(0, 0, 60, 16) )
,button(data, Fonts::pooh, "Test", sf::Vector2f(200, 400) )
{
}

void GuiTestState::input()
{

}

void GuiTestState::update(sf::Time deltaTime)
{
    /*buttons.update();

    switch(buttons.getSignal()){
        case 0:
            std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
            data->stateStack.pushState(std::move(toStack));
            break;
    }*/
}

void GuiTestState::draw()
{
    data->window.clear();

    //buttons.display();

    //button.display();
}


}
