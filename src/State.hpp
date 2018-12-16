#pragma once

#include <SFML/Graphics.hpp>

#include "resourceManager.hpp"

namespace States
{


class State
{
public:
    struct GameData
    {
        GameData(sf::RenderWindow & _window, Resources::TextureStorage & _textures);

        sf::RenderWindow & window;
        Resources::TextureStorage & textures;
    };

public:
    State(GameData & _gameData);

    virtual void input() = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw() = 0;

protected:
    void statePush();
    void statePop();
    void clearStateStack();

    GameData & gameData;
};


}

