#include <iostream>

#include "game.hpp"

int main()
{
    try
    {
        Game::Game game;
        game.run();
    }
    catch(const std::exception & except)
    {
        std::cout<<"Exception, what(): "<<except.what();
        std::cin.get();
    }

    return 0;
}
