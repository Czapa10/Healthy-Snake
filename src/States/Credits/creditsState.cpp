#include "creditsState.hpp"

namespace States
{


CreditsState::CreditsState(Game::GameDataRef data) : data(data)
,shouldComeBackToMenu(false)
,labels(data, Fonts::fipps,
    {   "Game was made by: ",
        "Grzegorz \"Czapa\" Bednorz - coding",
        "\"JumboCube\" - graphics",
        "Mateusz Stepka - music",
        "",
        "BACK TO MENU - ESC"
    },
    6, 30, 30, sf::Vector2i(), false
    )
{
    labels.getSnake().setIsShowing(false);
}

void CreditsState::input()
{

}

void CreditsState::update(sf::Time deltaTime)
{

}

void CreditsState::draw()
{
    data->window.clear();

    labels.display();
}


}
