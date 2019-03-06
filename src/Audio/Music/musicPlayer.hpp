#pragma once

#include <SFML/Audio.hpp>
#include <string>

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
