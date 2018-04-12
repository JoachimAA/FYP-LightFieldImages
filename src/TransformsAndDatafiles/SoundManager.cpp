#include "SoundManager.h"




void SoundManager::loadSound(std::string filename)
{
	if (!m_gameSound.loadFromFile(filename))
	{
		std::cout << "couldn't load sound/n";
	}
	m_gameSounds.push_back(m_gameSound);//put into sound vector
}

void SoundManager::playSound(int soundNum)
{
	//sound stored in sound buffer and set to a sound 
	m_sound.setBuffer(m_gameSounds[soundNum]);
	//sound used to play the buffer
	m_sound.play();
}
