#include "difficultyChoiseState.hpp"

#include "difficultyLevelIdentifiers.hpp"

#include <Resources/resourceIdentifiers.hpp>
#include <States/Game/gameState.hpp>
#include <States/Menu/menuState.hpp>

namespace States
{


DifficultyChoiseState::DifficultyChoiseState(Game::GameDataRef _data)
:data(_data)
,buttons(data, Textures::difficultyChoiseButtons, 4, 40, sf::Vector2i(47, 12), 6, sf::Vector2i(0, 50) )
,bestScoresDisplayer(data)
{
    background.setTexture(data->textures.get(Textures::gameBackground));
}

void DifficultyChoiseState::input()
{
    buttons.input();
}

void DifficultyChoiseState::update()
{
    buttons.update();
    changingState();
}

void DifficultyChoiseState::draw()
{
    data->window.clear();

    data->window.draw(background);
    buttons.display();
    bestScoresDisplayer.display();
}

void DifficultyChoiseState::changingState()
{
    if(buttons.getSignal() == 3){
        std::unique_ptr<States::MenuState> toStack(new States::MenuState(data));
        data->stateStack.pushState(std::move(toStack));
    }
    else{
        switch(buttons.getSignal()){
            case 0:   data->levelOfDifficulty = Difficulty::easy;     break;
            case 1:   data->levelOfDifficulty = Difficulty::medium;   break;
            case 2:   data->levelOfDifficulty = Difficulty::hard;     break;
            default:  return;
        }
        std::unique_ptr<States::GameState> toStack(new States::GameState(data));
        data->stateStack.pushState(std::move(toStack));
    }
}


}
