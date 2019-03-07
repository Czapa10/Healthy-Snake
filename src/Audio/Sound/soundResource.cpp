#include "soundResource.hpp"

namespace Audio
{

    namespace Sounds
    {

        Resource takeInitialData(ID id)
        {
            /// (file path, volume multiplier, loop)

            switch(id){
                case cat:
                    return Resource {"resources/sounds/cat.wav", 1, false};

                case eat:
                    return Resource {"resources/sounds/eat.wav", 0.6, false};

                case die:
                    return Resource {"resources/sounds/die.wav", 1, false};
            }

        }

    }

}
