#include "game.hpp"

#include <States/Splash/splashState.hpp>
#include <Save/SettingsSave/settings.hpp>

namespace Game
{


Game::Game()
{
    data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Healthy Snake");

    std::unique_ptr<States::SplashState> toStack(new States::SplashState(data));
    data->stateStack.pushState(std::move(toStack));

    loadTextures();
    loadFonts();

    Save::Settings settings = data->save.settingsSave.getSavedSettings();
    data->music.setVolume(settings.musicVolume);
    data->sound.setVolume(settings.soundVolume);
}

void Game::run()
{
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastRender = sf::Time::Zero;

    while(data->window.isOpen()){
        data->stateStack.processStateChanges();
        input();
        update();
        timeSinceLastRender += clock.restart();

        while(timeSinceLastRender > timePerFrame){
            timeSinceLastRender -= timePerFrame;
            render();
        }
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

void Game::update()
{
    data->stateStack.getActiveState()->update();
}

void Game::render()
{
    if(data->stateStack.areThereTwoStates()){
        data->stateStack.getPreviousState()->draw();
    }

    data->stateStack.getActiveState()->draw();

    data->window.display();
}

void Game::loadTextures() const
{
    loadSplashStateTextures();
    loadMenuStateTextures();
    loadDifficultyChoiceStateTextures();
    loadPauseStateTextures();
    loadGameOverStateTextures();
    loadFoodStatsStateTexture();
    loadGameStateTextures();
}

void Game::loadSplashStateTextures() const
{
    data->textures.load(Textures::companyLogo, "resources/textures/splashState/maineCoonLogo.jpg");
    data->textures.load(Textures::madeBy, "resources/textures/splashState/madeBy.png");
}

void Game::loadMenuStateTextures() const
{
    data->textures.load(Textures::menuButtons, "resources/textures/menuState/buttons.png");
    data->textures.load(Textures::menuLogoLabel, "resources/textures/menuState/logoLabel.png");
}

void Game::loadDifficultyChoiceStateTextures() const
{
    data->textures.load(Textures::difficultyChoiseButtons, "resources/textures/difficultyChoiseState/difficultyChoiseButtons.png");
}

void Game::loadPauseStateTextures() const
{
    data->textures.load(Textures::pause, "resources/textures/pauseState/pause.png");
}

void Game::loadGameOverStateTextures() const
{
    data->textures.load(Textures::gameover, "resources/textures/gameOverState/gameover.png");
}

void Game::loadFoodStatsStateTexture() const
{
    data->textures.load(Textures::foodList, "resources/textures/foodStatsState/foodList.png");
}

void Game::loadGameStateTextures() const
{
    data->textures.load(Textures::gameBackground, "resources/textures/gameState/gameBackground.jpg");

    data->textures.load(Textures::snakeStraightBody, "resources/textures/gameState/snakeStraightBody.png");
    data->textures.load(Textures::snakeTurnBody, "resources/textures/gameState/snakeTurnBody.png");

    loadHeadAndTail8x12();
    loadHeadAndTail8x8();

    loadFoodTextures();
    loadStatBarTextures();
}
//------------------------------------------------------------------------------------------
void Game::loadHeadAndTail8x12() const
{
    data->textures.load(Textures::snakeTail, "resources/textures/gameState/head&Tail8x12/snakeTail.png");
    data->textures.load(Textures::snakeHead, "resources/textures/gameState/head&Tail8x12/snakeHead.png");
    data->textures.load(Textures::snakeHeadOpenMouth, "resources/textures/gameState/head&Tail8x12/snakeHeadOpenMouth.png");
    data->textures.load(Textures::snakeHeadClosedEyes, "resources/textures/gameState/head&Tail8x12/snakeHeadClosedEyes.png");
    data->textures.load(Textures::snakeHeadBigEyesWhileDying, "resources/textures/gameState/head&Tail8x12/snakeHeadBigEyesWhileDying.png");
    data->textures.load(Textures::snakeHeadTounge, "resources/textures/gameState/head&Tail8x12/snakeHeadTounge.png");
    data->textures.load(Textures::snakeHeadClosedEyesWhileDying, "resources/textures/gameState/head&Tail8x12/snakeHeadClosedEyesWhileDying.png");
}

void Game::loadHeadAndTail8x8() const
{
    data->textures.load(Textures::snakeTail8x8, "resources/textures/gameState/head&Tail8x8/snakeTail.png");
    data->textures.load(Textures::snakeHead8x8, "resources/textures/gameState/head&Tail8x8/snakeHead.png");
    data->textures.load(Textures::snakeHeadOpenMouth8x8, "resources/textures/gameState/head&Tail8x8/snakeHeadOpenMouth.png");
    data->textures.load(Textures::snakeHeadClosedEyes8x8, "resources/textures/gameState/head&Tail8x8/snakeHeadClosedEyes.png");
    data->textures.load(Textures::snakeHeadBigEyesWhileDying8x8, "resources/textures/gameState/head&Tail8x8/snakeHeadBigEyesWhileDying.png");
    data->textures.load(Textures::snakeHeadTounge8x8, "resources/textures/gameState/head&Tail8x8/snakeHeadTounge.png");
    data->textures.load(Textures::snakeHeadClosedEyesWhileDying8x8, "resources/textures/gameState/head&Tail8x8/snakeHeadClosedEyesWhileDying.png");
}

void Game::loadFoodTextures() const
{
    data->textures.load(Textures::appleRed, "resources/textures/gameState/food/appleRed.png");
    data->textures.load(Textures::appleYellow, "resources/textures/gameState/food/appleYellow.png");
    data->textures.load(Textures::hamburger, "resources/textures/gameState/food/hamburger.png");
    data->textures.load(Textures::cherry, "resources/textures/gameState/food/cherry.png");
    data->textures.load(Textures::meat, "resources/textures/gameState/food/meat.png");
    data->textures.load(Textures::iceCream, "resources/textures/gameState/food/iceCream.png");
    data->textures.load(Textures::donut, "resources/textures/gameState/food/donut.png");
    data->textures.load(Textures::frites, "resources/textures/gameState/food/frites.png");
}

void Game::loadStatBarTextures() const
{
    data->textures.load(Textures::statisticsBar, "resources/textures/gameState/statBar/statBar.png");
    data->textures.load(Textures::numbers, "resources/textures/gameState/statBar/numbers.png");
    data->textures.load(Textures::minus, "resources/textures/gameState/statBar/minus.png");
}

void Game::loadFonts() const
{
    data->fonts.load(Fonts::fipps, "resources/fonts/Fipps-Regular.otf");
    data->fonts.load(Fonts::healthySnakeFont, "resources/fonts/HealthySnakeFont.ttf");
}


}
