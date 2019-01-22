#include "pauseState.hpp"
#include "gameState.hpp"
#include "menuState.hpp"

namespace States
{


PauseState::PauseState(Game::GameDataRef _data)
:data(_data)
{
    background.setTexture(data->textures.get(Textures::pause));
    background.setScale(4.f, 4.f);
}

void PauseState::input()
{
    if(timeFromChangeState.getElapsedTime().asSeconds() < 0.4)
        return;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        enterWasClicked = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        escWasClicked = true;
    }
}

void PauseState::update(sf::Time deltaTime)
{
    if(enterWasClicked){
        data->stateStack.popState();

    }
    else if(escWasClicked){
        data->stateStack.clearStates();
        std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
        data->stateStack.pushState(std::move(toStack));
    }
}

void PauseState::draw()
{
    data->window.draw(background);
}


}

