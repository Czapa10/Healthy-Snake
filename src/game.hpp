#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "resourceManager.hpp"
#include "stateStack.hpp"

namespace Game
{


struct GameData
{
    States::StateStack stateStack;
    sf::RenderWindow window;
    Resources::TextureStorage textures;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
    Game();
    void run();

private:
    void input();
    void update(sf::Time deltaTime);
    void render();

    void loadTextures();

private:

    GameDataRef data = std::make_shared<GameData>();
};


}
