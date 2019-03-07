#pragma once

#include <list>
#include <SFML/Audio.hpp>

#include <Resources/resourceManager.hpp>
#include "soundIdentifiers.hpp"

namespace Audio
{


class SoundPlayer : private sf::NonCopyable
{
public:
    SoundPlayer();

    void play(Sounds::ID);
    void removeStoppedSounds();

private:
    Resources::ResourceManager<sf::SoundBuffer, Sounds::ID> soundBufferStorage;
    std::list<sf::Sound> sounds;
    float volume;
};


}
