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
    void saveScore(int score, Difficulty::Level);
    void loadScore();

private:
    int easyBestScore{};
    int mediumBestScore{};
    int hardBestScore{};
};


}
