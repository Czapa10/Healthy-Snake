#include <string>

namespace Resources
{


    template <typename Resource, typename Identifier>
    void ResourceManager <Resource, Identifier>::load(Identifier id, const std::string& filename)
    {
        std::unique_ptr<Resource> resource(new Resource());

        resource->loadFromFile(filename);

        ResourceMap.insert(std::make_pair(id, std::move(resource)));
    }

    template <typename Resource, typename Identifier>
    Resource& ResourceManager <Resource, Identifier>::get(Identifier id)
    {
        auto found = ResourceMap.find(id);
        return *found->second;
    }


}
