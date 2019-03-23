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
        "", "", "", "",
        "BACK TO MENU - ESC"
    },
    10, 30, 30, sf::Vector2i(-150, 0), false, sf::Color(30, 54, 35)
    )

,specialThanks(data, Fonts::fipps,
    {
        "Special thanks to: "
    },
    1, 15, 15, sf::Vector2i(-150, 200), false, sf::Color(30, 54, 35)
    )

{
    mainLabels.getSnake().setIsShowing(false);
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
