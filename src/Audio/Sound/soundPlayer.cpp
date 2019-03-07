#include "soundPlayer.hpp"

namespace Audio
{


SoundPlayer::SoundPlayer()
{
    soundBufferStorage.load(Sounds::cat, "resources/sounds/cat.wav");
    soundBufferStorage.load(Sounds::eat, "resources/sounds/eat.wav");
    soundBufferStorage.load(Sounds::die, "resources/sounds/die.wav");
}

void SoundPlayer::play(Sounds::ID soundID)
{
    removeStoppedSounds();

    sounds.push_back(sf::Sound(soundBufferStorage.get(soundID)));
    sounds.back().play();
}

void SoundPlayer::removeStoppedSounds()
{
    sounds.remove_if( [] (const sf::Sound& s)
    {
        return s.getStatus() == sf::Sound::Stopped;
    } );
}


}
