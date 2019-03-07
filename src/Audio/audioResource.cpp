#include "audioResource.hpp"

namespace Audio
{


Resource::Resource(std::string filepath, float volumeMultiplier, bool loop)
:filepath(filepath)
,volumeMultiplier(volumeMultiplier)
,loop(loop)
{
}


}
