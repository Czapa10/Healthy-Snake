#pragma once

#include <string>

namespace Audio
{


struct Resource
{
    Resource(std::string filepath, float volumeMultiplier = 1, bool loop = false, float secondsToRemove = 0);

    std::string filepath;
    float volumeMultiplier;
    bool loop;
    float secondsToRemove; ///time after start playing to stop playing // if 0 this won't happen
};


}
