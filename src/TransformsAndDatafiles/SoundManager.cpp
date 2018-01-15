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
	m_sound.setBuffer(m_gameSound);
	m_sound.play();
}
