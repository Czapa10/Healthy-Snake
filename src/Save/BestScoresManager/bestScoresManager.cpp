#include "bestScoresManager.hpp"

#include <fstream>
#include <string>

namespace Save
{


BestScoresManager::BestScoresManager()
{
    loadScore();
}

void BestScoresManager::transferScore(int score, Difficulty::Level level)
{
    switch(level)
    {
        case Difficulty::easy:{
            if(score > easyBestScore){
                easyBestScore = score;
                saveScore(score, level);
            }
            break;
        }

        case Difficulty::medium:{
            if(score > mediumBestScore){
                mediumBestScore = score;
                saveScore(score, level);
            }
            break;
        }

        case Difficulty::hard:{
            if(score > hardBestScore){
                hardBestScore = score;
                saveScore(score, level);
            }
            break;
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

void BestScoresManager::saveScore(int score, Difficulty::Level level)
{
    std::ofstream file("best.hssave", std::ios::out | std::ios::binary);

    file.write( (char*)&easyBestScore,   sizeof(int) );
    file.write( (char*)&mediumBestScore, sizeof(int) );
    file.write( (char*)&hardBestScore,   sizeof(int) );

    file.close();
}

void BestScoresManager::loadScore()
{
    std::ifstream file("best.hssave", std::ios::in | std::ios::binary);

    if(!file){
        easyBestScore = 0;
        mediumBestScore = 0;
        hardBestScore = 0;
    }
    else{
        file.read((char*)&easyBestScore,   sizeof(int) );
        file.read((char*)&mediumBestScore, sizeof(int) );
        file.read((char*)&hardBestScore,   sizeof(int) );
    }

    file.close();
}


}
