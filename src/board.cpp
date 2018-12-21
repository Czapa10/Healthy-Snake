#include "gameState.hpp"

namespace GameElements
{


Board::Board()
{
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 48; j++){
            tiles[i][j].setID(Textures::gameBackground);
        }
    }
}


}
