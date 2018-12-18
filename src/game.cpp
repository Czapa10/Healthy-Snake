#include "game.hpp"
#include "splashState.hpp"

namespace Game
{


Game::Game()
{
    data->window.create(sf::VideoMode(800, 800), "Healthy Snake");
    data->stateStack.pushState(StateRef(new SplashState(data)));

    loadTextures();
}

void Game::run()
{
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(data->window.isOpen()){
        data->stateStack.processStateChanges();
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

    data->stateStack.getActiveState()->input();
}

void Game::update(sf::Time deltaTime)
{
    data->stateStack.getActiveState()->update(timePerFrame);
}

void Game::render()
{
    data->stateStack.getActiveState()->draw();
}

void Game::loadTextures()
{
    data->textures.load(Textures::companyLogo, "resources/textures/maineCoonLogo.jpg");
}


}
