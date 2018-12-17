#pragma once

#include <SFML/Graphics.hpp>

#include "resourceManager.hpp"

namespace Game
{


struct GameData
{
    //StateStack stateStack;
    sf::RenderWindow window;
    Resources::TextureStorage textures;
};

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

    sf::Sprite sprite;
};


}
