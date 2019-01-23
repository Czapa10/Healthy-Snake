#pragma once

#include <SFML/Graphics.hpp>

#include <states/state.hpp>
#include <game.hpp>

namespace States
{


class MenuState : public State
{
public:
    MenuState(Game::GameDataRef _data);

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    void menuKeyboardControl();
    void menuMouseControl();

    void updatingMenuGraphics();
    void changingState() const;

private:
    Game::GameDataRef data;

    int isOnButtonNr{1};
    bool buttonWasClicked{false};
    sf::Clock clock;

    sf::Sprite background;
    sf::Text play;
    sf::Text settings;
    sf::Text credits;
    sf::Text bestScore;
    sf::Text exit;

    sf::Vector2i mouseCurrentPos;
    sf::Vector2i mouseLastPos;
    sf::IntRect buttons[5];
};


}
