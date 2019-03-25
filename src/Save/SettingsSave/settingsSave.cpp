#include "settingsSave.hpp"

#include <fstream>

namespace Save
{


auto SettingsSave::getSavedSettings() -> const Settings&
{
    std::ifstream file("settings.hssave", std::ios::in | std::ios::binary);

    if(!file){
        return Settings{20, 13};
    }
    else{
        Settings settings;

        file.read((char*)&settings.musicVolume, sizeof(float) );
        file.read((char*)&settings.soundVolume, sizeof(float) );
    }

    file.close();
}

void SettingsSave::save(Settings settings)
{
    std::ofstream file("settings.hssave", std::ios::out | std::ios::binary);

    file.write( (char*)&settings.musicVolume, sizeof(float) );
    file.write( (char*)&settings.soundVolume, sizeof(float) );

    file.close();
}


}
