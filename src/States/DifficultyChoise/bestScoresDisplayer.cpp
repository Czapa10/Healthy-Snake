#include "bestScoresDisplayer.hpp"
#include <Resources/resourceIdentifiers.hpp>
#include <States/DifficultyChoise/difficultyLevelIdentifiers.hpp>

namespace States
{


BestScoresDisplayer::BestScoresDisplayer(Game::GameDataRef data)
: GUI::ButtonContainer(data, Fonts::fipps,
        {
        "BEST: " + std::to_string( data->save.bestScoresManager.getScore(Difficulty::easy) ),
        "BEST: " + std::to_string( data->save.bestScoresManager.getScore(Difficulty::medium) ),
        "BEST: " + std::to_string( data->save.bestScoresManager.getScore(Difficulty::hard) ),
        }, 3, 78, 25, sf::Vector2i(-330, 0), false, sf::Color(30, 54, 35)
    )
{
    getSnake().setIsShowing(false);
}


}
