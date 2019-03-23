#include "foodStatsState.hpp"

namespace States
{


FoodStatsState::FoodStatsState(Game::GameDataRef data) :data(data)
{
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
}


}
