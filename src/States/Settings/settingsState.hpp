#pragma once

#include <States/State.hpp>
#include <game.hpp>
#include <GUI/buttonContainer.hpp>

namespace States
{


class SettingsState : public State
{
public:
    SettingsState(Game::GameDataRef _data);

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    Game::GameDataRef data;

    sf::Sprite background;
    sf::Text settingsLabel;

    GUI::ButtonContainer buttons;

    bool settingsHaveJustChanged;

    int musicVolume = 521;
    int soundVolume = 521;
};


}
