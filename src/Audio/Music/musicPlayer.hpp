#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <map>

#include "musicIndentifiers.hpp"

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

private:
    sf::Music music;
    std::map<Music::ID, std::string> filenames;
    float volume;
};


}
