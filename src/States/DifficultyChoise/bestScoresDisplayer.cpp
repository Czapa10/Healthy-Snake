#include "bestScoresDisplayer.hpp"
#include <Resources/resourceIdentifiers.hpp>

namespace States
{


BestScoresDisplayer::BestScoresDisplayer(Game::GameDataRef data)
: GUI::ButtonContainer(data, Fonts::fipps,
        {
        "BEST:",
        "BEST:",
        "BEST:"
        }, 3, 78, 25, sf::Vector2i(-430, 0), false, sf::Color(30, 54, 35)
    )
{
    getSnake().setIsShowing(false);
}


}
