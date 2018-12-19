#include "menuState.hpp"

#include <iostream>

namespace States
{


MenuState::MenuState(Game::GameDataRef _data) : data(_data)
{
}

void MenuState::init()
{
    background.setTexture(data->textures.get(Textures::menuBackground1));

    unsigned int characterSize{80};

    play.setFont(data->fonts.get(Fonts::pooh));
    play.setColor(sf::Color(9,102,20));
    play.setCharacterSize(characterSize);
    play.setPosition(100.f, 305.f);
    play.setString("PLAY");

    settings.setFont(data->fonts.get(Fonts::pooh));
    settings.setColor(sf::Color(17, 194, 225));
    settings.setCharacterSize(characterSize);
    settings.setPosition(100.f, 405.f);
    settings.setString("SETTINGS");

    credits.setFont(data->fonts.get(Fonts::pooh));
    credits.setColor(sf::Color::Yellow);
    credits.setCharacterSize(characterSize);
    credits.setPosition(100.f, 505.f);
    credits.setString("CREDITS");

    bestScore.setFont(data->fonts.get(Fonts::pooh));
    bestScore.setColor(sf::Color(239,104,14));
    bestScore.setCharacterSize(characterSize);
    bestScore.setPosition(100.f, 605.f);
    bestScore.setString("BEST SCORES");

    exit.setFont(data->fonts.get(Fonts::pooh));
    exit.setColor(sf::Color::Red);
    exit.setCharacterSize(characterSize);
    exit.setPosition(100.f, 705.f);
    exit.setString("EXIT");
}

void MenuState::input()
{
    sf::Event event;

    std::cout<<clock.getElapsedTime().asSeconds()<<std::endl;

    if((sf::Event::KeyPressed)&&(clock.getElapsedTime().asSeconds() > 0.17f)){
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))||(sf::Keyboard::isKeyPressed(sf::Keyboard::W))){
            --isOnButtonNr;
            if(isOnButtonNr == 0)
                isOnButtonNr = 5;

            clock.restart();
        }

        else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))||(sf::Keyboard::isKeyPressed(sf::Keyboard::S))&&(clock.getElapsedTime().asSeconds() > 0.3)){
            ++isOnButtonNr;
            if(isOnButtonNr == 6)
                isOnButtonNr = 1;

            clock.restart();
        }
    }else{
        sf::Vector2i currentMousePos = data->mouseInput.getMousePos(data->window);

        sf::IntRect buttons[5];
        int top = 300;
        for(auto button : buttons){
            button.left = 0;
            button.top = top; top += 100;
            button.width = 600;
            button.height = 100;
        }

        if(mouseLastPos != currentMousePos){
            for(int i = 0; i < 5; ++i){
                if(data->mouseInput.isUnderMouse(buttons[5], data->window))
                    isOnButtonNr = i;
            }
        }

        mouseLastPos = currentMousePos;
    }


}

void MenuState::update(sf::Time deltaTime)
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

void MenuState::draw()
{
    data->window.clear();

    data->window.draw(background);

    data->window.draw(play);
    data->window.draw(settings);
    data->window.draw(credits);
    data->window.draw(bestScore);
    data->window.draw(exit);

    data->window.display();
}


}
