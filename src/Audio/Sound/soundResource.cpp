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
                    return Resource {"resources/sounds/cat.wav", 3.2};

                case eat:
                    return Resource {"resources/sounds/eat.wav", 0.6};

                case buttonClick:
                    return Resource {"resources/sounds/buttonClick.wav"};

                case menuMove:
                    return Resource {"resources/sounds/menuMove.wav", 0.35};
            }

        }

    }

}
