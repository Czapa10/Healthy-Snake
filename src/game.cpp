#include "game.hpp"

namespace Game
{


Game::Game()
{
    data->window.create(sf::VideoMode(800, 800), "Healthy Snake");
    //add splash state
    loadTextures();
}

void Game::run()
{
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(data->window.isOpen()){
        input();
        timeSinceLastUpdate += clock.restart();

        while(timeSinceLastUpdate > timePerFrame){
            timeSinceLastUpdate -= timePerFrame;
            input();
            update(timePerFrame);
        }
        render();
    }
}

void Game::input()
{
    sf::Event event;

    while(data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed)
            data->window.close();
    }
}

void Game::update(sf::Time deltaTime)
{

}

void Game::render()
{
    data->window.clear(sf::Color::White);

    data->window.draw(sprite);

    data->window.display();
}

void Game::loadTextures()
{
    data->textures.load(Textures::companyLogo, "resources/textures/maineCoonLogo.jpg");

    sprite.setTexture(data->textures.get(Textures::companyLogo));
    sprite.setPosition(0.f, 50.f);
}


}
