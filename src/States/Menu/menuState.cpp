#include "menuState.hpp"

#include <States/DifficultyChoise/difficultyChoiseState.hpp>

#include <iostream>

namespace States
{


MenuState::MenuState(Game::GameDataRef _data) : data(_data)
{
    background.setTexture(data->textures.get(Textures::menuBackground1));

    unsigned int characterSize{80};

    play.setFont(data->fonts.get(Fonts::pooh));
    play.setFillColor(sf::Color(9,102,20));
    play.setCharacterSize(characterSize);
    play.setPosition(100.f, 295.f);
    play.setString("PLAY");

    settings.setFont(data->fonts.get(Fonts::pooh));
    settings.setFillColor(sf::Color(17, 194, 225));
    settings.setCharacterSize(characterSize);
    settings.setPosition(100.f, 391.f);
    settings.setString("SETTINGS");

    credits.setFont(data->fonts.get(Fonts::pooh));
    credits.setFillColor(sf::Color::Yellow);
    credits.setCharacterSize(characterSize);
    credits.setPosition(100.f, 487.f);
    credits.setString("CREDITS");

    bestScore.setFont(data->fonts.get(Fonts::pooh));
    bestScore.setFillColor(sf::Color(239,104,14));
    bestScore.setCharacterSize(characterSize);
    bestScore.setPosition(100.f, 583.f);
    bestScore.setString("BEST SCORES");

    exit.setFont(data->fonts.get(Fonts::pooh));
    exit.setFillColor(sf::Color::Red);
    exit.setCharacterSize(characterSize);
    exit.setPosition(100.f, 679.f);
    exit.setString("EXIT");

    int top = 292;
    for(auto & button : buttons){
        button.left = 0;
        button.top = top; top += 96;
        button.width = 700;
        button.height = 96;
    }
}

void MenuState::input()
{
    menuKeyboardControl();
    menuMouseControl();
}

void MenuState::update(const sf::Time& deltaTime)
{
    updatingMenuGraphics();
    changingState();

    buttonWasClicked = false; /// <-- it's temporary (Delete it when all menu options in menu will be done)
}

void MenuState::draw()
{
    data->window.clear();

    data->window.draw(background);

    data->window.draw(play);
    data->window.draw(settings);
    data->window.draw(credits);
    data->window.draw(bestScore);
    data->window.draw(exit);
}

//private_methods****************************************************************
void MenuState::menuKeyboardControl()
{
    sf::Event event;

    if(sf::Event::KeyPressed){
        if(clock.getElapsedTime().asSeconds() > 0.17f){
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))||(sf::Keyboard::isKeyPressed(sf::Keyboard::W))){
                --isOnButtonNr;
                if(isOnButtonNr == 0)
                    isOnButtonNr = 5;

                clock.restart();
            }

            else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))||(sf::Keyboard::isKeyPressed(sf::Keyboard::S))){
                ++isOnButtonNr;
                if(isOnButtonNr == 6)
                    isOnButtonNr = 1;

                clock.restart();
            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                buttonWasClicked = true;
            }
        }
    }
}

void MenuState::menuMouseControl()
{
    mouseCurrentPos = sf::Mouse::getPosition(data->window);

    if(mouseLastPos != mouseCurrentPos){
        for(int i = 0; i < 5; ++i){
            if(data->mouseInput.isUnderMouse(buttons[i], data->window)){
                isOnButtonNr = ++i;
                break;
            }
        }
    }

    for(int i = 0; i < 5; ++i){
        if(data->mouseInput.isClicked(buttons[i], data->window)){
            buttonWasClicked = true;
            break;
        }
    }

    mouseLastPos = mouseCurrentPos;
}


void MenuState::updatingMenuGraphics()
{
    switch(isOnButtonNr){
        case 1:
            background.setTexture(data->textures.get(Textures::menuBackground1));
            break;

        case 2:
            background.setTexture(data->textures.get(Textures::menuBackground2));
            break;

        case 3:
            background.setTexture(data->textures.get(Textures::menuBackground3));
            break;

        case 4:
            background.setTexture(data->textures.get(Textures::menuBackground4));
            break;

        case 5:
            background.setTexture(data->textures.get(Textures::menuBackground5));
            break;
    }
}

void MenuState::changingState() const
{
    if(buttonWasClicked){
        switch(isOnButtonNr){
            case 1:{
                std::unique_ptr<States::DifficultyChoiseState> toStack(new States::DifficultyChoiseState(data));
                data->stateStack.pushState(std::move(toStack));
                break;
            }
            case 2:
                std::cout<<"to settings"<<std::endl;
                break;

            case 3:
                std::cout<<"to credits state"<<std::endl;
                break;

            case 4:
                std::cout<<"to best score state"<<std::endl;
                break;

            case 5:
                data->window.close();
                break;
        }
    }
}


}
