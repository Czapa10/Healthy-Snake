#include "menuState.hpp"

#include <States/DifficultyChoise/difficultyChoiseState.hpp>

#include <iostream>

namespace States
{


MenuState::MenuState(Game::GameDataRef _data) : data(_data)
{
    background.setTexture(data->textures.get(Textures::gameBackground));


}

void MenuState::input()
{
}

void MenuState::update(sf::Time deltaTime)
{

}

void MenuState::draw()
{
    data->window.clear();

    data->window.draw(background);


}

//private_methods****************************************************************

void MenuState::changingState() const
{
    #if 0
    switch(isOnButtonNr){
        case 1:{
            std::unique_ptr<States::DifficultyChoiseState> toStack(new States::DifficultyChoiseState(data));
            data->stateStack.pushState(std::move(toStack));
            break;
        }
        case 2:
            std::cout<<"to settings"<<std::endl;
            break;

        case 3:
            std::cout<<"to credits state"<<std::endl;
            break;

        case 4:
            std::cout<<"to best score state"<<std::endl;
            break;

        case 5:
            data->window.close();
            break;
    }
    #endif // 0
}


}
