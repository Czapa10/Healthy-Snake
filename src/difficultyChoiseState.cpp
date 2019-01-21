#include "difficultyChoiseState.hpp"

#include "resourceIdentifiers.hpp"

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
    buttons[0].setTextureRect(sf::IntRect(0, 0, 29, 12));
    buttons[1].setTextureRect(sf::IntRect(36, 0, 43, 10));
    buttons[2].setTextureRect(sf::IntRect(86, 0, 28, 10));
    buttons[3].setTextureRect(sf::IntRect(121, 0, 29, 10));

    for(auto &button : buttons){
        button.setScale(8.f, 5.f);
    }
}

void DifficultyChoiseState::input()
{

}

void DifficultyChoiseState::update(sf::Time deltaTime)
{

}

void DifficultyChoiseState::draw()
{
    data->window.clear(sf::Color::Green);

    for(auto button : buttons){
        data->window.draw(button);
    }
}


}
