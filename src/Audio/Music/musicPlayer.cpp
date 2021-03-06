#include "musicPlayer.hpp"
#include "musicResource.hpp"

#include <iostream>

namespace Audio
{


MusicPlayer::MusicPlayer()
:volume(20.f)
,id(Music::none)
{
}

void MusicPlayer::play(Music::ID themeID)
{
    if(themeID == id)
        return;

    id = themeID;
    Resource res = Music::takeInitialData(themeID);
    music.openFromFile(res.filepath);
    music.setVolume(volume * res.volumeMultiplier);
    music.setLoop(res.loop);
    music.setPitch(1);

    music.play();
}

void MusicPlayer::stop()
{
    music.stop();
}

void MusicPlayer::setPaused(bool paused)
{
    if(paused)
        music.pause();
    else
        music.play();
}

void MusicPlayer::setVolume(float volume)
{
    this->volume = volume;

    Resource res = Music::takeInitialData(id);
    music.setVolume(volume * res.volumeMultiplier);
}

void MusicPlayer::setPitch(float pitch)
{
    music.setPitch(pitch);
}

float MusicPlayer::getVolume()
{
    return this->volume;
}



}
