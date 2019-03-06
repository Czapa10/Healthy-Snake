#pragma once

#include <SFML/Audio.hpp>
#include <vector>

#include <Resources/resourceManager.hpp>

#include "soundIndentifiers.hpp"

namespace Audio
{


class AudioManager
{
public:
    AudioManager();

    setMusic();
    stopMusic();

    addSound();

private:
    sf::Music currentMusic;
    Resources::ResourceManager<sf::SoundBuffer, Sounds::ID> soundBufferStorage;
    std::vector<sf::Sound> sounds;
};


}
