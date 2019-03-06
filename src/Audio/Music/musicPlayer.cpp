#include "musicPlayer.hpp"

#include <iostream>

namespace Audio
{


MusicPlayer::MusicPlayer()
:music()
,filenames()
,volume(50.f)
{
    filenames[Music::menuTheme]     = "../../../resources/music/menu.wav";
    filenames[Music::gameplayTheme] = "../../../resources/music/game.wav";
}


void MusicPlayer::play(Music::ID themeID)
{
    std::string filename = filenames[themeID];

    if(! music.openFromFile(filename))
        std::cout<<filename<<" couldn't be loaded. Probably because it does not exist."<<std::endl;

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
