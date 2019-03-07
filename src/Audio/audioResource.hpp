#pragma once

#include <string>

namespace Audio
{


struct Resource
{
    Resource(std::string filepath, float volumeMultiplier = 1, bool loop = false);

    std::string filepath;
    float volumeMultiplier;
    bool loop;
};


}
