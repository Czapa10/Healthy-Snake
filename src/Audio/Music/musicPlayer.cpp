#include "musicPlayer.hpp"

#include <istream>

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
    std::string filename = filename[themeID];

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
    music.pause();
}

void MusicPlayer::setVolume(float volume)
{
    music.setVolume();
}


}
