#include "settingsState.hpp"

#include <States/Menu/menuState.hpp>
#include <Resources/resourceIdentifiers.hpp>

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
,background(data->textures.get(Textures::gameBackground))
,settingsLabel("SETTINGS", data->fonts.get(Fonts::fipps), 50)
,buttons(data, Fonts::fipps,
{
    "Music volume: " + std::to_string(data->music.getVolume() / 2.6),
    "Sound volume: " + std::to_string(5),
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
            musicVolume /= 2.6;

            if(musicVolume = 10)
                musicVolume = 0;
            else
                ++musicVolume;

            std::string strMusicVol = "Music volume: " + std::to_string(musicVolume);
            buttons[0].getText().setString(strMusicVol);

            data->music.setVolume(musicVolume * 2.6);

            break;
        }
        case 1:{
            /*soundVolume += 1;
            std::string strSoundVol = "Sound volume: " + std::to_string(soundVolume);
            buttons[1].getText().setString(strSoundVol);*/
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

