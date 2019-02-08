#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "button.hpp"

namespace GUI
{


class ButtonContainer
{
public:
    ButtonContainer(int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2i offset = sf::Vector2i(0,0), bool isRegular = true);

private:
    const int numberOfButtons;
    const int spaceBetweenButtons;
    sf::Vector2i buttonSize;
    sf::Vector2i offset;
    bool isRegular;

    std::vector<Button> buttons;
};


}
