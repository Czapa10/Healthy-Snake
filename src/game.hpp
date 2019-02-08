#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include <Resources/resourceManager.hpp>
#include <States/stateStack.hpp>
#include <GUI/mouseInput.hpp>
#include <States/DifficultyChoise/difficultyLevelIdentifiers.hpp>


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768


namespace Game
{


struct GameData
{
    States::StateStack stateStack;
    sf::RenderWindow window;
    Resources::TextureStorage textures;
    Resources::FontStorage fonts;
    Input::MouseInput mouseInput;
    Difficulty::Level levelOfDifficulty;
};

using GameDataRef = std::shared_ptr<GameData>;


class Game
{
public:
    Game();
    void run();

private:
    void input();
    void update(sf::Time deltaTime);
    void render();

    ///loading textures
    void loadTextures() const;

    void loadSplashStateTextures() const;
    void loadMenuStateTextures() const;
    void loadDifficultyChoiceStateTextures() const;
    void loadPauseStateTextures() const;
    void loadGameOverStateTextures() const;
    void loadGameStateTextures() const;

    void loadHeadAndTail8x12() const;
    void loadHeadAndTail8x8() const;
    void loadFoodTextures() const;
    void loadStatBarTextures() const;

    void loadFonts() const;

private:
    GameDataRef data = std::make_shared<GameData>();
};


}
