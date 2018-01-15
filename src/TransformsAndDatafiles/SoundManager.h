#pragma once

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H


#include <SFML\Audio.hpp>
#include <iostream>

class SoundManager {

public:
	
	void loadSound();
	void playSound();

	std::string apple = "../TransformsAndDatafiles/assets/Apple.wav";
   // std::vector<sf::Sound> m_gameSounds;

	sf::Sound m_sound;

	sf::SoundBuffer m_gameSound;

private:

	

};

#endif