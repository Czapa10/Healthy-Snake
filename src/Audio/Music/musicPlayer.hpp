#pragma once

#include <SFML/Audio.hpp>
#include <string>

#include "musicIdentifiers.hpp"

namespace Audio
{


class MusicPlayer : private sf::NonCopyable
{
public:
    MusicPlayer();

    void play(Music::ID);
    void stop();

    void setPaused(bool paused);
    void setVolume(float volume);
    void setPitch(float pitch);
    float getVolume();

private:
    sf::Music music;
    Music::ID id;
    float volume;
};


}
