#include "gameOverState.hpp"
#include "gameState.hpp"
#include "menuState.hpp"

namespace States
{


GameOverState::GameOverState(Game::GameDataRef _data)
:data(_data)
{
}

void GameOverState::init()
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

void GameOverState::update(sf::Time deltaTime)
{
    if(enterWasClicked){
        std::unique_ptr<States::GameState> toStack(new States::GameState(data));
        data->stateStack.pushState(std::move(toStack));
    }
    else if(escWasClicked){
        std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
        data->stateStack.pushState(std::move(toStack));
    }
}

void GameOverState::draw()
{
    data->window.clear();

    data->window.draw(background);

    data->window.display();
}


}
