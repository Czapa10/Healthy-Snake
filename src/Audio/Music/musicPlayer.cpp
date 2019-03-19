#include "musicPlayer.hpp"
#include "musicResource.hpp"

#include <iostream>

namespace Audio
{


MusicPlayer::MusicPlayer()
:volume(20.f)
{
}

void MusicPlayer::play(Music::ID themeID)
{
    Resource res = Music::takeInitialData(themeID);
    music.openFromFile(res.filepath);
    music.setVolume(volume * res.volumeMultiplier);
    music.setLoop(res.loop);

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
    music.setVolume(volume);
}


}
