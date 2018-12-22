#include "game.hpp"
#include "splashState.hpp"

namespace Game
{


Game::Game()
{
    data->window.create(sf::VideoMode(1024, 768), "Healthy Snake");

    std::unique_ptr<States::SplashState> temp(new States::SplashState(data));
    data->stateStack.pushState(std::move(temp));

    loadTextures();
    loadFonts();
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
    data->stateStack.getActiveState()->update(deltaTime);
}

void Game::render()
{
    data->stateStack.getActiveState()->draw();
}

void Game::loadTextures()
{
    ///splash state
    data->textures.load(Textures::companyLogo, "resources/textures/maineCoonLogo.jpg");
    data->textures.load(Textures::madeBy, "resources/textures/madeBy.png");

    ///menu state
    data->textures.load(Textures::menuBackground1, "resources/textures/menuBackground1.png");
    data->textures.load(Textures::menuBackground2, "resources/textures/menuBackground2.png");
    data->textures.load(Textures::menuBackground3, "resources/textures/menuBackground3.png");
    data->textures.load(Textures::menuBackground4, "resources/textures/menuBackground4.png");
    data->textures.load(Textures::menuBackground5, "resources/textures/menuBackground5.png");

    ///game state
    data->textures.load(Textures::gameBackground, "resources/textures/gameBackground.png");
    data->textures.load(Textures::grass, "resources/textures/grass.jpg");
    data->textures.load(Textures::snakeStraightBody, "resources/textures/snakeStraightBody.png");
    data->textures.load(Textures::snakeHead, "resources/textures/snakeHead.png");
    data->textures.load(Textures::snakeTail, "resources/textures/snakeTail.png");
    data->textures.load(Textures::snakeTurnBody, "resources/textures/snakeTurnBody.png");
}

void Game::loadFonts()
{
    data->fonts.load(Fonts::pooh, "resources/fonts/Pooh.ttf");
}


}
