#include "soundPlayer.hpp"
#include "soundResource.hpp"
#include <Audio/audioResource.hpp>

namespace Audio
{


SoundPlayer::SoundPlayer()
:volume()
{
    soundBufferStorage.load(Sounds::cat, Sounds::takeInitialData(Sounds::cat).filepath);
    soundBufferStorage.load(Sounds::eat, Sounds::takeInitialData(Sounds::eat).filepath);
    soundBufferStorage.load(Sounds::buttonClick, Sounds::takeInitialData(Sounds::buttonClick).filepath);
    soundBufferStorage.load(Sounds::menuMove, Sounds::takeInitialData(Sounds::menuMove).filepath);
}

void SoundPlayer::play(Sounds::ID soundID)
{
    removeStoppedSounds();

    Resource sett = Sounds::takeInitialData(soundID);

    sf::Sound sound(soundBufferStorage.get(soundID));
    sound.setVolume(volume * sett.volumeMultiplier);
    sound.setLoop(sett.loop);

    sounds.push_back(std::move(sound));
    sounds.back().play();
}

void SoundPlayer::removeStoppedSounds()
{
    sounds.remove_if( [] (const sf::Sound& s)
    {
        return s.getStatus() == sf::Sound::Stopped;
    } );
}

void SoundPlayer::removeEverySound()
{
    sounds.clear();
}

void SoundPlayer::setVolume(float volume)
{
    this->volume = volume;
    sounds.back().setVolume(volume); //this is only for button click sound when we change sound volume it in settings
}

float SoundPlayer::getVolume()
{
    return this->volume;
}


}
