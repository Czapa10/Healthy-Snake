#pragma once

#include <States/State.hpp>
#include <game.hpp>
#include <GUI/buttonContainer.hpp>

namespace States
{


class SettingsState : public State
{
public:
    SettingsState(Game::GameDataRef);

    void input() override;
    void update() override;
    void draw() override;

private:
    void setMusicVolume();
    void setSoundVolume();
    void goToMenu();

private:
    Game::GameDataRef data;

    sf::Sprite background;
    sf::Text settingsLabel;

    GUI::ButtonContainer buttons;
};


}
