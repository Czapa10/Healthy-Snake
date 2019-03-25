#pragma once

#include "settings.hpp"

namespace Save
{


struct SettingsSave
{
    auto getSavedSettings() -> const Settings&;
    void save(Settings);
};


}
