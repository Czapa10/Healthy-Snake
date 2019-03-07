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
                    return Resource {"resources/sounds/cat.wav"};

                case eat:
                    return Resource {"resources/sounds/eat.wav", 0.6};

                case die:
                    return Resource {"resources/sounds/die.wav"};
            }

        }

    }

}
