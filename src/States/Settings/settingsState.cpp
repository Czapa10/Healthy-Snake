#include "pauseState.hpp"

namespace States
{


SettingsState::SettingsState(Game::GameDataRef _data)
:data(_data)
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
    data->window.draw(background);
}


}

