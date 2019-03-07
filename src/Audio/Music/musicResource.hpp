#pragma once

#include "musicIndentifiers.hpp"
#include <string>

namespace Audio
{

    namespace Music
    {
        struct Resource
        {
            std::string filepath;
            float volumeMultiplier;
            bool loop;
        };

        Resource takeInitialData(ID);
    }

}
