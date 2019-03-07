#include "audioResource.hpp"

namespace Audio
{


Resource::Resource(std::string filepath, float volumeMultiplier, bool loop, float secondsToRemove)
:filepath(filepath)
,volumeMultiplier(volumeMultiplier)
,loop(loop)
,secondsToRemove(secondsToRemove)
{
}


}
