#include "menuState.hpp"

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

}

void MenuState::update(sf::Time deltaTime)
{

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
