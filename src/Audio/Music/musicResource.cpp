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
                    return Resource {"resources/music/menu.wav", 0.98, true};

                case gameplayTheme:
                    return Resource {"resources/music/game.wav", 0.88, true};

                case gameOverTheme:
                    return Resource {"resources/music/gameOver.wav", 1.4, false};
            }

        }

    }

}
