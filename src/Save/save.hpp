#pragma once

#include <memory>

#include "BestScoresManager/bestScoresManager.hpp"
#include "SettingsSave/settingsSave.hpp"
#include <game.hpp>

namespace Save
{


struct Save
{
    Save();

    std::unique_ptr<BestScoresManager> bestScoresManager;
    std::unique_ptr<SettingsSave> settingsSave;
};

Save::Save()
:bestScoresManager( new BestScoresManager() )
,settingsSave( new SettingsSave() )
{
}


}
