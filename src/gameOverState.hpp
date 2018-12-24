#pragma once

namespace States
{


class GameOverState : public State
{
public:
    GameOverState(Game::GameDataRef _data);

    void init();

    void input();
    void update(sf::Time deltaTime);
    void draw();

private:
    Game::GameDataRef data;
};


}
