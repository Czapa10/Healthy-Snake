#pragma once

#include "iostream"
#include <sstream>

#include "splashState.hpp"

namespace States
{


SplashState::SplashState(Game::GameDataRef _data) : data(_data)
{
}

void SplashState::init()
{
    background.setTexture(data->textures.get(Textures::companyLogo));
}

void SplashState::input()
{

}

void SplashState::update(sf::Time deltaTime)
{
    if(change){
        clock.restart();
        ++whichLogo;
    }

    switch(whichLogo){
        case 1:
            if(clock.getElapsedTime().asSeconds() > 2){
                change = true;
            }
            break;

        case 2:
            if(change){
                background.setTexture(data->textures.get(Textures::name));
                change = false;
            }

            if(clock.getElapsedTime().asSeconds() > 2.5){
                change = true;
            }

            break;

        case 3:
            if(change){
                background.setTexture(data->textures.get(Textures::madeBy));
                change = false;
            }

            if(clock.getElapsedTime().asSeconds() > 2){
                std::cout<<"Go to menu"<<std::endl;
            }
    }


}

void SplashState::draw()
{
    data->window.clear(sf::Color::White);

    data->window.draw(background);

    data->window.display();
}


}
