#pragma once

#include <States/DifficultyChoise/difficultyLevelIdentifiers.hpp>

namespace Save
{


class BestScoresManager
{
public:
    BestScoresManager();

    void transferScore(int score, Difficulty::Level);
    int getScore(Difficulty::Level) const;

private:
    void saveScore(Difficulty::Level);
    void loadScore();

private:
    int easyBestScore = 5;
    int mediumBestScore = -12;
    int hardBestScore = 100;
};


}
