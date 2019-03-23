#include "foodStatsState.hpp"
#include <Audio/Sound/soundIdentifiers.hpp>

namespace States
{


FoodStatsState::FoodStatsState(Game::GameDataRef data) : data(data)
,shouldComeBackToMenu(false)
,background(data->textures.get(Textures::gameBackground))
,foodList(data->textures.get(Textures::foodList))
,toMenu("back to menu - ESC", data->fonts.get(Fonts::fipps), 30)
{
    foodList.setPosition(263, 10);

    toMenu.setFillColor(sf::Color(30, 54, 35));
    toMenu.setPosition(275, 680);
}

void FoodStatsState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        shouldComeBackToMenu = true;
}

void FoodStatsState::update(sf::Time deltaTime)
{
    if(shouldComeBackToMenu){
        data->sound.play(Audio::Sounds::buttonClick);
        data->stateStack.popState();
    }
}

void FoodStatsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    data->window.draw(foodList);
    data->window.draw(toMenu);
}


}
