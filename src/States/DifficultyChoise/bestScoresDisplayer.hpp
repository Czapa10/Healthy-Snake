#pragma once

#include <GUI/buttonContainer.hpp>
#include <game.hpp>

namespace States
{


class BestScoresDisplayer : public GUI::ButtonContainer
{
public:
    BestScoresDisplayer(Game::GameDataRef);

    update();
};


}
