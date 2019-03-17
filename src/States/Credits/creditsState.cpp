#include "creditsState.hpp"
#include <Resources/resourceIdentifiers.hpp>

namespace States
{


CreditsState::CreditsState(Game::GameDataRef data) : data(data)
,shouldComeBackToMenu(false)
,background(data->textures.get(Textures::gameBackground))
,labels(data, Fonts::fipps,
    {   "Game was made by: ",
        "",
        " Grzegorz \"Czapa\" Bednorz - coding",
        "\"JumboCube\" - graphics",
        "Mateusz Stepka - music",
        "",
        "BACK TO MENU - ESC"
    },
    7, 30, 30, sf::Vector2i(0, 0), false, sf::Color(30, 54, 35)
    )
{
    labels.getSnake().setIsShowing(false);
}

void CreditsState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        shouldComeBackToMenu = true;
}

void CreditsState::update(sf::Time deltaTime)
{
    if(shouldComeBackToMenu)
        data->stateStack.popState();
}

void CreditsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    labels.display();
}


}
