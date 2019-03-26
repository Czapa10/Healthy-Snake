#include "menuState.hpp"

#include <States/DifficultyChoise/difficultyChoiseState.hpp>
#include <States/Credits/creditsState.hpp>
#include <States/Settings/settingsState.hpp>
#include <States/FoodStats/foodStatsState.hpp>
#include <Resources/resourceIdentifiers.hpp>
#include <Audio/Music/musicIdentifiers.hpp>

#include <iostream>

namespace States
{


MenuState::MenuState(Game::GameDataRef _data)
:data(_data)
,buttons(data, Textures::menuButtons, 5, 30, sf::Vector2i(60, 15), 5, sf::Vector2i(0, 100) )
{
    buttons.getSnake().setSnakePos(350, 80);

    background.setTexture(data->textures.get(Textures::gameBackground));

    logoLabel.setTexture(data->textures.get(Textures::menuLogoLabel));
    logoLabel.scale(3.f, 3.f);
    logoLabel.setPosition( (SCREEN_WIDTH - logoLabel.getTexture()->getSize().x * logoLabel.getScale().x) / 2, 40.f);

    data->music.play(Audio::Music::menuTheme);
}

void MenuState::input()
{
    buttons.input();
}

void MenuState::update()
{
    buttons.update();
    changingState();
}

void MenuState::draw()
{
    data->window.clear();

    data->window.draw(background);
    data->window.draw(logoLabel);
    buttons.display();
}

void MenuState::changingState()
{
    switch(buttons.getSignal()){
        case 0:{
                std::unique_ptr<States::DifficultyChoiseState> toStack(new States::DifficultyChoiseState(data));
                data->stateStack.pushState(std::move(toStack));
                break;
            }
        case 1:{
                std::unique_ptr<States::SettingsState> toStack(new States::SettingsState(data));
                data->stateStack.pushState(std::move(toStack));
                break;
            }
        case 2:{
                std::unique_ptr<States::FoodStatsState> toStack(new States::FoodStatsState(data));
                data->stateStack.pushState(std::move(toStack), false);
                break;
            }
        case 3:{
                std::unique_ptr<States::CreditsState> toStack(new States::CreditsState(data));
                data->stateStack.pushState(std::move(toStack), false);
                break;
            }
        case 4:
            data->window.close();
            break;
    }

    buttons.resetSignal();
}


}
