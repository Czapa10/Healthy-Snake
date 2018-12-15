#pragma once

#include <SFML/Graphics.hpp>

#include "resourceManager.hpp"

namespace Game
{


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
    sf::RenderWindow window;
    Resources::ResourceManager <sf::Texture, Textures::ID> textures;
};


}
