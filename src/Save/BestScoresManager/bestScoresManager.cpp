#include "bestScoresManager.hpp"

namespace Save
{


BestScoresManager::BestScoresManager()
{
}

void BestScoresManager::transferScore(int score, Difficulty::Level level)
{
    switch(level)
    {
        case Difficulty::easy:{
            if(score > easyBestScore){
                easyBestScore = score;
                saveScore(level);
            }
        }

        case Difficulty::medium:{
            if(score > mediumBestScore){
                mediumBestScore = score;
                saveScore(level);
            }
        }

        case Difficulty::hard:{
            if(score > hardBestScore){
                hardBestScore = score;
                saveScore(level);
            }
        }
    }
}

int BestScoresManager::getScore(Difficulty::Level level) const
{
    switch(level)
    {
        case Difficulty::easy:      return easyBestScore;
        case Difficulty::medium:    return mediumBestScore;
        case Difficulty::hard:      return hardBestScore;
    }
}

void BestScoresManager::saveScore(Difficulty::Level level)
{

}

void BestScoresManager::loadScore()
{

}


}
