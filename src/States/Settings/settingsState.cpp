#include "settingsState.hpp"
#include <Resources/resourceIdentifiers.hpp>

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
,background(data->textures.get(Textures::gameBackground))
{

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
}


}

