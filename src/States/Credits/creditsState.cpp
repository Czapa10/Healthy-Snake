#include "creditsState.hpp"
#include <Resources/resourceIdentifiers.hpp>

namespace States
{


CreditsState::CreditsState(Game::GameDataRef data) : data(data)
,shouldComeBackToMenu(false)
,background(data->textures.get(Textures::gameBackground))

,mainLabels(data, Fonts::fipps,
    {   "Game was made by: ",
        "",
        " Grzegorz \"Czapa\" Bednorz - coding",
        "\"JumboCube\" - graphics",
        "Mateusz Stepka - music & sound",
        "", "", "", "", "",
        "BACK TO MENU - ESC"
    },
    11, 30, 30, sf::Vector2i(-200, 0), false, sf::Color(30, 54, 35)
    )

,specialThanks(data, Fonts::fipps,
    {
        "Special thanks to: ",
        "Hubert Misiewicz - for making pull requests (5 commits)",
        "Filip Kwiatkowski - for code review and help with code issues",
        "Piotr Gardocki - for code review and help with code issues",
        "\"Thrall\" - for beta testing",
        "\"Rudy\" - for beta testing"
    },
    6, 20, 19, sf::Vector2i(-290, 120), false, sf::Color(30, 54, 35)
    )

{
    mainLabels.getSnake().setIsShowing(false);
    specialThanks.getSnake().setIsShowing(false);
}

void CreditsState::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        shouldComeBackToMenu = true;
}

void CreditsState::update(sf::Time deltaTime)
{
    if(shouldComeBackToMenu){
        data->sound.play(Audio::Sounds::buttonClick);
        data->stateStack.popState();
    }
}

void CreditsState::draw()
{
    data->window.clear();

    data->window.draw(background);
    mainLabels.display();
    specialThanks.display();
}


}
