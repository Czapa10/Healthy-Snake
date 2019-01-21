#include "difficultyChoiseState.hpp"

#include "resourceIdentifiers.hpp"
#include "difficultyLevelIdentifiers.hpp"
#include "gameState.hpp"
#include "menuState.hpp"

namespace States
{


DifficultyChoiseState::DifficultyChoiseState(Game::GameDataRef _data) : data(_data)
{
    for(auto &button : buttons){
        button.setTexture(data->textures.get(Textures::difficultyChoiseButtons));
    }
    for(int i = 0; i < 4; ++i){
        buttons[i].setPosition(365.f, 100 * i + 250);
    }
    for(auto &button : buttons){
        button.setScale(8.f, 5.f);
    }
}

void DifficultyChoiseState::input()
{
    ///menu keyboard control
    sf::Event event;
    int whichButtonWasClicked{}; //0 - means any button was not clicked

    if(sf::Event::KeyPressed){
        if(clock.getElapsedTime().asSeconds() > 0.17f){
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))||(sf::Keyboard::isKeyPressed(sf::Keyboard::W))){
                --isOnButtonNr;
                if(isOnButtonNr == 0)
                    isOnButtonNr = 4;

                clock.restart();
            }

            else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))||(sf::Keyboard::isKeyPressed(sf::Keyboard::S))){
                ++isOnButtonNr;
                if(isOnButtonNr == 5)
                    isOnButtonNr = 1;

                clock.restart();
            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                wasClicked = true;
            }
        }
    }
}

void DifficultyChoiseState::update(sf::Time deltaTime)
{
    buttons[0].setTextureRect(sf::IntRect(0, 0, 29, 12));
    buttons[1].setTextureRect(sf::IntRect(36, 0, 43, 10));
    buttons[2].setTextureRect(sf::IntRect(86, 0, 28, 10));
    buttons[3].setTextureRect(sf::IntRect(121, 0, 29, 10));

    switch(isOnButtonNr){
        case 1:
            buttons[0].setTextureRect(sf::IntRect(0, 12, 29, 16));
            break;

        case 2:
            buttons[1].setTextureRect(sf::IntRect(36, 11, 43, 16));
            break;

        case 3:
            buttons[2].setTextureRect(sf::IntRect(86, 11, 28, 16));
            break;

        case 4:
            buttons[3].setTextureRect(sf::IntRect(121, 11, 29, 16));
            break;
    }


    ///menu mouse control
    mouseCurrentPos = sf::Mouse::getPosition(data->window);

    if(mouseLastPos != mouseCurrentPos){
        for(int i = 0; i < 4; ++i){
            if(data->mouseInput.isUnderMouse(buttons[i], data->window)){
                isOnButtonNr = ++i;
                break;
            }
        }
    }

    if(clock.getElapsedTime().asSeconds() > 0.34)
    for(int i = 0; i < 4; ++i){
        if(data->mouseInput.isClicked(buttons[i], data->window)){
            wasClicked = true;
            break;
        }
    }

    mouseLastPos = mouseCurrentPos;


    if(wasClicked){
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

void DifficultyChoiseState::draw()
{
    data->window.clear(sf::Color::Green);

    for(auto button : buttons){
        data->window.draw(button);
    }
}


}
