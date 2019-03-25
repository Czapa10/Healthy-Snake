#pragma once

#include <memory>

#include "BestScoresManager/bestScoresManager.hpp"
#include "SettingsSave/settingsSave.hpp"
#include <game.hpp>

namespace Save
{


struct Save
{
    BestScoresManager bestScoresManager;
    SettingsSave settingsSave;
};


}
