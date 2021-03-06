#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "resourceIdentifiers.hpp"

namespace Resources
{


template <typename Resource, typename Identifier>
class ResourceManager
{
public:
    void load(Identifier id, const std::string& filename);
    Resource& get(Identifier id);

public:
    std::map <Identifier, std::unique_ptr<Resource>> ResourceMap;
};

using TextureStorage = ResourceManager<sf::Texture, Textures::ID>;
using FontStorage = ResourceManager<sf::Font, Fonts::ID>;

}

#include "resourceManager.inl"
