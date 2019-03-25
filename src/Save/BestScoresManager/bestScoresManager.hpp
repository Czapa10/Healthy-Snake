#pragma once

#include <States/DifficultyChoise/difficultyLevelIdentifiers.hpp>

namespace Save
{


class BestScoresManager
{
public:
    BestScoresManager();

    void transferScore(int score);
    int getScore(Difficulty::Level) const;

private:
    void saveScore();
    void loadScore();

private:
    int easyBestScore;
    int mediumBestScore;
    int hardBestScore;
};


}
