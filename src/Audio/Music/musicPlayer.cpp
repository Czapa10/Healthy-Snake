#include "musicPlayer.hpp"

#include <iostream>

namespace Audio
{


MusicPlayer::MusicPlayer()
:music()
,filenames()
,volume(13.f)
{
    filenames[Music::menuTheme]     = "resources/music/menu.wav";
    filenames[Music::gameplayTheme] = "resources/music/game.wav";

    setVolume(volume);
}

void MusicPlayer::play(Music::ID themeID)
{
    std::string filename = filenames[themeID];

    music.openFromFile(filename);

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
