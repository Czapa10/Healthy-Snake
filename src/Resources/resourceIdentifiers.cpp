#include "resourceIdentifiers.hpp"
#include <iostream>

namespace Textures
{
    ID operator!(ID textureID)
    {
        switch(textureID){
            case snakeHead:                         return snakeHead8x8;
            case snakeHeadOpenMouth:                return snakeHeadOpenMouth8x8;
            case snakeHeadClosedEyes:               return snakeHeadClosedEyes8x8;
            case snakeHeadTounge:                   return snakeHeadTounge8x8;
            case snakeHeadBigEyesWhileDying:        return snakeHeadBigEyesWhileDying8x8;
            case snakeHeadClosedEyesWhileDying:     return snakeHeadClosedEyesWhileDying8x8;

            case snakeHead8x8:                      return snakeHead;
            case snakeHeadOpenMouth8x8:             return snakeHeadOpenMouth;
            case snakeHeadClosedEyes8x8:            return snakeHeadClosedEyes;
            case snakeHeadTounge8x8:                return snakeHeadTounge;
            case snakeHeadBigEyesWhileDying8x8:     return snakeHeadBigEyesWhileDying;
            case snakeHeadClosedEyesWhileDying8x8:  return snakeHeadClosedEyesWhileDying;

            default: return textureID;
        }
    }
}
