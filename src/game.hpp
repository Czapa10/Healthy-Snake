#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "resourceManager.hpp"
#include "stateStack.hpp"
#include "mouseInput.hpp"

namespace Game
{


struct GameData
{
    States::StateStack stateStack;
    sf::RenderWindow window;
    Resources::TextureStorage textures;
    Resources::FontStorage fonts;
    Input::MouseInput mouseInput;
};

using GameDataRef = std::shared_ptr<GameData>;


class Game
{
public:
    Game();
    void run() const;

private:
    void input() const;
    void update(sf::Time deltaTime) const;
    void render() const;

    void loadTextures() const;
    void loadFonts() const;

private:
    GameDataRef data = std::make_shared<GameData>();
};


}
