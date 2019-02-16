#include "difficultyChoiseState.hpp"

#include "difficultyLevelIdentifiers.hpp"

#include <Resources/resourceIdentifiers.hpp>
#include <States/Game/gameState.hpp>
#include <States/Menu/menuState.hpp>

namespace States
{


DifficultyChoiseState::DifficultyChoiseState(Game::GameDataRef _data) : data(_data)
{
    background.setTexture(data->textures.get(Textures::gameBackground));


}

void DifficultyChoiseState::input()
{

}

void DifficultyChoiseState::update(sf::Time deltaTime)
{

}

void DifficultyChoiseState::draw()
{
    data->window.clear();

    data->window.draw(background);


}

void DifficultyChoiseState::changingState()
{
    if(isOnButtonNr == 4){
        std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
        data->stateStack.pushState(std::move(toStack));
    }
    else{
        switch(isOnButtonNr){
            case 1:
                data->levelOfDifficulty = Difficulty::easy;
                break;

            case 2:
                data->levelOfDifficulty = Difficulty::medium;
                break;

            case 3:
                data->levelOfDifficulty = Difficulty::hard;
                break;
        }
        std::unique_ptr<States::GameState> toStack(new States::GameState(data));
        data->stateStack.pushState(std::move(toStack));
    }
}


}
