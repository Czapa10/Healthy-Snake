#include "foodStatsState.hpp"

namespace States
{


FoodStatsState::FoodStatsState(Game::GameDataRef data) : data(data)
,background(data->textures.get(Textures::gameBackground))
,foodList(data->textures.get(Textures::foodList))
{
    foodList.setPosition(263, 75);
}

void FoodStatsState::input()
{
}

void FoodStatsState::update(sf::Time deltaTime)
{
}

void FoodStatsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    data->window.draw(foodList);
}


}
