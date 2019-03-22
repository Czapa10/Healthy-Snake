#include "settingsState.hpp"

#include <States/Menu/menuState.hpp>
#include <Resources/resourceIdentifiers.hpp>

#include <iostream>

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
,background(data->textures.get(Textures::gameBackground))
,settingsLabel("SETTINGS", data->fonts.get(Fonts::fipps), 50)
,buttons(data, Fonts::fipps,
{
    "Music volume: " + std::to_string( static_cast<int>(data->music.getVolume() / 4) ),
    "Sound volume: " + std::to_string( static_cast<int>( static_cast<float>(data->sound.getVolume() / 2.6) ) ),
    "save & exit"
}
, 3, 40, 35, sf::Vector2i(), false, sf::Color(30, 54, 35))
{
    settingsLabel.setColor(sf::Color(30, 54, 35));
    settingsLabel.setPosition(324, 30);
}

void SettingsState::input()
{
    buttons.input();
}

void SettingsState::update(sf::Time deltaTime)
{
    buttons.update();

    switch(buttons.getSignal()){
        case 0:{
            int musicVolume = data->music.getVolume();
            musicVolume /= 4;

            if(musicVolume == 10)
                musicVolume = 0;
            else
                ++musicVolume;

            std::string strMusicVol = "Music volume: " + std::to_string(static_cast<int>(musicVolume));
            buttons[0].getText().setString(strMusicVol);

            data->music.setVolume(musicVolume * 4);

            break;
        }
        case 1:{
            float soundVolume = data->sound.getVolume();
            std::cout<<"vol 1: "<<soundVolume<<std::endl;
            soundVolume /= 2.6;
            std::cout<<"vol 2: "<<soundVolume<<std::endl;

            if(soundVolume == 10)
                soundVolume = 0;
            else
                ++soundVolume;

            std::cout<<"vol 3: "<<soundVolume<<std::endl;

            std::string strSoundVol = "Sound volume: " + std::to_string(static_cast<int>(soundVolume));
            buttons[1].getText().setString(strSoundVol);

            data->sound.setVolume(soundVolume * 2.6);

            std::cout<<"vol 4: "<<soundVolume * 2.6<<std::endl;

            break;
        }
        case 2:{
            std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
            data->stateStack.pushState(std::move(toStack));
            break;
        }
    }

    buttons.resetSignal();
}

void SettingsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    data->window.draw(settingsLabel);
    buttons.display();
}


}

