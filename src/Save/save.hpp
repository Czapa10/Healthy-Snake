#pragma once

#include <memory>

#include "BestScoresManager/bestScoresManager.hpp"
#include "SettingsSave/settingsSave.hpp"

namespace Save
{


struct Save
{
    std::unique_ptr<BestScoresManager> bestScoresManager;
    std::unique_ptr<SettingsSave> settingsSave;
};


}
