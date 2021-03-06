#include "settingsState.hpp"

#include <States/Menu/menuState.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include <Save/SettingsSave/settings.hpp>

#include <iostream>

namespace Save{ struct Settings; }

namespace States
{


SettingsState::SettingsState(Game::GameDataRef data)
:data(data)
,background(data->textures.get(Textures::gameBackground))
,settingsLabel("SETTINGS", data->fonts.get(Fonts::fipps), 50)
,buttons(
    data, Fonts::fipps,
    {
        "Music volume: " + std::to_string( static_cast<int>(data->music.getVolume() / 4) ),
        "Sound volume: " + std::to_string( static_cast<int>( static_cast<float>(data->sound.getVolume() / 2.6) ) ),
        "save & exit"
    }
    , 3, 40, 35, sf::Vector2i(), false, sf::Color(30, 54, 35)
)
{
    settingsLabel.setColor(sf::Color(30, 54, 35));
    settingsLabel.setPosition(324, 30);

    buttons.getSnake().setSnakePos(100, 100);
}

void SettingsState::input()
{
    buttons.input();
}

void SettingsState::update()
{
    buttons.update();

    switch(buttons.getSignal()){
        case 0: setMusicVolume(); break;
        case 1: setSoundVolume(); break;
        case 2: goToMenu();       break;
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

void SettingsState::setMusicVolume()
{
    int musicVolume = data->music.getVolume();
    musicVolume /= 4;

    if(musicVolume == 10)
        musicVolume = 0;
    else
        ++musicVolume;

    std::string strMusicVol = "Music volume: " + std::to_string(static_cast<int>(musicVolume));
    buttons[0].getText().setString(strMusicVol);

    data->music.setVolume(musicVolume * 4);
}

void SettingsState::setSoundVolume()
{
    float soundVolume = data->sound.getVolume();
    soundVolume /= 2.6;

    if(soundVolume == 10)
        soundVolume = 0;
    else
        ++soundVolume;

    std::string strSoundVol = "Sound volume: " + std::to_string(static_cast<int>(soundVolume));
    buttons[1].getText().setString(strSoundVol);

    data->sound.setVolume(soundVolume * 2.6);
}

void SettingsState::goToMenu()
{
    data->save.settingsSave.save( Save::Settings{ data->music.getVolume(), data->sound.getVolume() } );

    std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
    data->stateStack.pushState(std::move(toStack));
}


}

