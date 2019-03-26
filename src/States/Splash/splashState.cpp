#include "splashState.hpp"

#include <States/Menu/menuState.hpp>
#include <Audio/Sound/soundIdentifiers.hpp>

namespace States
{


SplashState::SplashState(Game::GameDataRef _data) : data(_data)
{
    data->sound.play(Audio::Sounds::cat);
}

void SplashState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
            std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
            data->stateStack.pushState(std::move(toStack));
        }
    }
}

void SplashState::update()
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
                data->sound.removeEverySound();
            }
            break;

        case 2:
            if(change){
                background.setTexture(data->textures.get(Textures::madeBy));
                background.setPosition(112.f, 0.f);
                change = false;
            }

            if(clock.getElapsedTime().asSeconds() > 2){
                std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
                data->stateStack.pushState(std::move(toStack));
            }
    }


}

void SplashState::draw()
{
    data->window.clear(sf::Color::White);

    data->window.draw(background);
}


}
