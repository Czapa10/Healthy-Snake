#pragma once

#include <SFML/Graphics.hpp>

#include "resourceManager.hpp"
#include "stateIdentifiers.hpp"

namespace States
{

class StateStack;

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
    State(GameData & _gameData, StateStack & _stateStack);

    virtual void input() = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw() = 0;

protected:
    void statePush(ID id);
    void statePop();
    void clearStateStack();

    GameData & gameData;

private:
    StateStack & stateStack;
};


}

