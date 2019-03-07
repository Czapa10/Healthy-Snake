#include "splashState.hpp"

#include <States/Menu/menuState.hpp>
#include <States/GUItest/guiTestState.hpp>
#include <Audio/Sound/soundIdentifiers.hpp>

namespace States
{


SplashState::SplashState(Game::GameDataRef _data) : data(_data)
{
    //data->sound.play(Audio::Sounds::cat);
}

void SplashState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
            std::unique_ptr<States::MenuState> temp(new States::MenuState(data));
            data->stateStack.pushState(std::move(temp));
        }
    }

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    && (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
    && (sf::Keyboard::isKeyPressed(sf::Keyboard::I))){
        std::unique_ptr<States::GuiTestState> temp(new States::GuiTestState(data));
        data->stateStack.pushState(std::move(temp));
    }
}

void SplashState::update(sf::Time deltaTime)
{
    if(change){
        clock.restart();
        ++whichLogo;
    }

    switch(whichLogo){
        case 1:
            if(change){
                background.setTexture(data->textures.get(Textures::companyLogo));
                change = false;
            }

            if(clock.getElapsedTime().asSeconds() > 2){
                change = true;
            }
            break;

        case 2:
            if(change){
                background.setTexture(data->textures.get(Textures::madeBy));
                background.setPosition(112.f, 0.f);
                change = false;
            }

            if(clock.getElapsedTime().asSeconds() > 2){
                std::unique_ptr<States::MenuState> temp(new States::MenuState(data));
                data->stateStack.pushState(std::move(temp));
            }
    }


}

void SplashState::draw()
{
    data->window.clear(sf::Color::White);

    data->window.draw(background);
}


}
