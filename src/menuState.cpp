#include "menuState.hpp"

namespace States
{


MenuState::MenuState(Game::GameDataRef _data) : data(_data)
{
}

void MenuState::init()
{
    background.setTexture(data->textures.get(Textures::menuBackground1));
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

    data->window.display();
}


}
