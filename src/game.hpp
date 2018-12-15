#pragma once

#include <SFML/Graphics.hpp>

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

private:
    sf::RenderWindow window;
};


}
