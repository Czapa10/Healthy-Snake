#include "musicResource.hpp"

namespace Audio
{

    namespace Music
    {

        Resource takeInitialData(ID id)
        {
            /// (file path, volume multiplier, loop)

            switch(id){
                case menuTheme:
                    return Resource {"resources/music/menu.wav", 0.85, true};

                case gameplayTheme:
                    return Resource {"resources/music/game.wav", 1.30, true};
            }

        }

    }

}
