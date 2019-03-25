#pragma once

#include "settings.hpp"

namespace Save
{


struct SettingsSave
{
    auto getSavedSettings() -> Settings;
    void save(Settings);
};


}
