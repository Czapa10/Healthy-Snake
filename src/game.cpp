#include "game.hpp"

namespace Game
{


Game::Game()
:window(sf::VideoMode(800, 900), "Healthy Snake")
{
}

void Game::run()
{
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(window.isOpen()){
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

    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time deltaTime)
{

}

void Game::render()
{
    window.clear();

    window.display();
}


}
