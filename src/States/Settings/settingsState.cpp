#include "settingsState.hpp"
#include <Resources/resourceIdentifiers.hpp>

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
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

}

void SettingsState::update(sf::Time deltaTime)
{

}

void SettingsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    data->window.draw(settingsLabel);
    buttons.display();
}


}

