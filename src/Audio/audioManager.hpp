#pragma once

#include <SFML/Audio.hpp>
#include <vector>

namespace Audio
{


class AudioManager
{
public:
    setMusic();
    stopMusic();

    addSound();

private:
    sf::Music currentMusic;
    std::vector<sf::SoundBuffer> soundBuffers;
    std::vector<sf::Sound> sounds;
};


}
