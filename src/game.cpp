#include "game.hpp"

#include <States/Splash/splashState.hpp>

namespace Game
{


Game::Game()
{
    data->window.create(sf::VideoMode(1024, 768), "Healthy Snake");

    std::unique_ptr<States::SplashState> toStack(new States::SplashState(data));
    data->stateStack.pushState(std::move(toStack));

    loadTextures();
    loadFonts();
}

void Game::run() const
{
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(data->window.isOpen()){
        data->stateStack.processStateChanges();
        input();
        update(timePerFrame);
        timeSinceLastUpdate += clock.restart();

        while(timeSinceLastUpdate > timePerFrame){
            timeSinceLastUpdate -= timePerFrame;
            render();
        }
    }
}

void Game::input() const
{
    sf::Event event;

    while(data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed)
            data->window.close();
    }

    data->stateStack.getActiveState()->input();
}

void Game::update(sf::Time deltaTime) const
{
    data->stateStack.getActiveState()->update(deltaTime);
}

void Game::render() const
{
    if(data->stateStack.areThereTwoStates()){
        data->stateStack.getPreviousState()->draw();
    }

    data->stateStack.getActiveState()->draw();

    data->window.display();
}

void Game::loadTextures() const
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
    data->textures.load(Textures::gameBackground, "resources/textures/gameBackground.jpg");

    data->textures.load(Textures::snakeStraightBody, "resources/textures/snakeStraightBody.png");
    data->textures.load(Textures::snakeTail, "resources/textures/snakeTail.png");
    data->textures.load(Textures::snakeTurnBody, "resources/textures/snakeTurnBody.png");
    data->textures.load(Textures::snakeHead, "resources/textures/snakeHead.png");
    data->textures.load(Textures::snakeHeadOpenMouth, "resources/textures/snakeHeadOpenMouth.png");
    data->textures.load(Textures::snakeHeadClosedEyes, "resources/textures/snakeHeadClosedEyes.png");
    data->textures.load(Textures::snakeHeadBigEyesWhileDying, "resources/textures/snakeHeadBigEyesWhileDying.png");
    data->textures.load(Textures::snakeHeadTounge, "resources/textures/snakeHeadTounge.png");
    data->textures.load(Textures::snakeHeadClosedEyesWhileDying, "resources/textures/snakeHeadClosedEyesWhileDying.png");

    data->textures.load(Textures::appleRed, "resources/textures/appleRed.png");
    data->textures.load(Textures::appleYellow, "resources/textures/appleYellow.png");
    data->textures.load(Textures::hamburger, "resources/textures/hamburger.png");
    data->textures.load(Textures::cherry, "resources/textures/cherry.png");
    data->textures.load(Textures::meat, "resources/textures/meat.png");
    data->textures.load(Textures::iceCream, "resources/textures/iceCream.png");
    data->textures.load(Textures::donut, "resources/textures/donut.png");
    data->textures.load(Textures::frites, "resources/textures/frites.png");

    data->textures.load(Textures::statisticsBar, "resources/textures/statBar.png");
    data->textures.load(Textures::numbers, "resources/textures/numbers.png");
    data->textures.load(Textures::minus, "resources/textures/minus.png");

    data->textures.load(Textures::gameover, "resources/textures/gameover.png");

    data->textures.load(Textures::pause, "resources/textures/pause.png");

    data->textures.load(Textures::difficultyChoiseButtons, "resources/textures/difficultyChoiseButtons.png");
}

void Game::loadFonts() const
{
    data->fonts.load(Fonts::pooh, "resources/fonts/Pooh.ttf");
}


}
