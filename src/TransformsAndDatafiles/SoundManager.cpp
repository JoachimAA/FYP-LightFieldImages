#include "SoundManager.h"




void SoundManager::loadSound()
{
	if (!m_gameSound.loadFromFile("../../TransformsAndDatafiles/assets/Apple.wav"))
	{
		std::cout << "couldn't load sound/n";
	}

	//m_gameSounds.push_back(apple);
}

void SoundManager::playSound()
{
	//sound stored in sound buffer and set to a sound 
	m_sound.setBuffer(m_gameSound);
	//sound used to play the buffer
	m_sound.play();
}
