#pragma once

#include <string>

namespace Audio
{


struct Resource
{
    std::string filepath;
    float volumeMultiplier;
    bool loop;
};


}
