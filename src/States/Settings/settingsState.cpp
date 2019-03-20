#include "settingsState.hpp"
#include <Resources/resourceIdentifiers.hpp>

#include <iostream>

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
,settingsHaveJustChanged(false)
,background(data->textures.get(Textures::gameBackground))
,settingsLabel("SETTINGS", data->fonts.get(Fonts::fipps), 50)
,buttons(data, Fonts::fipps,
    {
        "Music volume: ",
        "Sound volume: ",
        "save & exit",
    },
        3, 40, 35, sf::Vector2i(), false, sf::Color(30, 54, 35))
{
    settingsLabel.setColor(sf::Color(30, 54, 35));
    settingsLabel.setPosition(324, 30);
}

void SettingsState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        settingsHaveJustChanged = true;
    }
}

void SettingsState::update(sf::Time deltaTime)
{
    if(settingsHaveJustChanged){
        std::string strMusicVol = buttons[0].getText().getString() + std::to_string(musicVolume);
        //std::string strMusicVol = std::to_string(musicVolume);
        buttons[0].getText().setString(strMusicVol);

        std::string strSoundVol = std::to_string(musicVolume);
        buttons[1].getText().setString( buttons[1].getText().getString() + strSoundVol );
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

