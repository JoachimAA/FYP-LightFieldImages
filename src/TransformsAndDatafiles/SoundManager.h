#pragma once

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H


#include <SFML\Audio.hpp>
#include <iostream>

class SoundManager {

public:
	
	
	void loadSound(std::string filename);
	void playSound(int soundNum);

	
    std::vector<sf::SoundBuffer> m_gameSounds;
	sf::Sound m_sound;
	sf::SoundBuffer m_gameSound;

private:

	

};

#endif