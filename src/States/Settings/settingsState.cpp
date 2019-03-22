#include "settingsState.hpp"
#include <Resources/resourceIdentifiers.hpp>

#include <iostream>

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
,settingsHaveJustChanged(true)
,background(data->textures.get(Textures::gameBackground))
,settingsLabel("SETTINGS", data->fonts.get(Fonts::fipps), 50)
,buttons(data, Fonts::fipps,{"", "", "save & exit",}, 3, 40, 35, sf::Vector2i(), false, sf::Color(30, 54, 35))
{
    settingsLabel.setColor(sf::Color(30, 54, 35));
    settingsLabel.setPosition(324, 30);
}

void SettingsState::input()
{

}

void SettingsState::update(sf::Time deltaTime)
{
    switch(buttons.getSignal()){
        case 0:{
            musicVolume += 1;
        }
        case 1:{
            soundVolume += 1;
        }

    }

    if(settingsHaveJustChanged){
        std::string strMusicVol = "Music volume: " + std::to_string(musicVolume);
        buttons[0].getText().setString(strMusicVol);

        std::string strSoundVol = "Sound volume: " + std::to_string(soundVolume);
        buttons[1].getText().setString(strSoundVol);
    }

    settingsHaveJustChanged = false;
}

void SettingsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    data->window.draw(settingsLabel);
    buttons.display();
}


}

