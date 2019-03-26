#include "gameOverState.hpp"

#include <States/Game/gameState.hpp>
#include <States/Menu/menuState.hpp>

namespace States
{


GameOverState::GameOverState(Game::GameDataRef _data)
:data(_data)
{
    background.setTexture(data->textures.get(Textures::gameover));
}

void GameOverState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        enterWasClicked = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        escWasClicked = true;
    }
}

void GameOverState::update()
{
    if(enterWasClicked){
        data->sound.play(Audio::Sounds::buttonClick);

        data->stateStack.clearStates();
        std::unique_ptr<States::GameState> toStack(new States::GameState(data));
        data->stateStack.pushState(std::move(toStack));
    }
    else if(escWasClicked){
        data->sound.play(Audio::Sounds::buttonClick);

        data->stateStack.clearStates();
        std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
        data->stateStack.pushState(std::move(toStack));
    }
}

void GameOverState::draw()
{
    data->window.draw(background);
}


}
