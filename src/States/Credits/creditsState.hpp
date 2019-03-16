#pragma once

#include <States/State.hpp>
#include <GUI/buttonContainer.hpp>

namespace States
{


class CreditsState : public State
{
public:
    CreditsState();

    void input() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

private:
    GUI::ButtonContainer labels;
};


}
