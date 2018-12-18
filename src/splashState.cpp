#pragma once

#include "iostream"
#include <sstream>

#include "splashState.hpp"

namespace States
{


SplashState::SplashState(GameDataRef _data) : data(_data)
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
    if(clock.getElapsedTime().asSeconds() > 2){
        std::cout<<"Go to menu"<<std::endl;
    }
}

void SplashState::draw()
{
    data->window.clear(sf::Color::White);

    data->window.draw(background);

    data->window.display();
}


}
