#include "SplashScreen.h"
#include <iostream>

void SplashScreen::load()
{
	m_playButton.setUp(580.0f, 250.0f, 120.0f, 50.0f);
	m_background.setUp(0, 0, 1280,720, "../../TransformsAndDatafiles/assets/SplashScreenBackground.png");
}

void SplashScreen::render(sf::RenderWindow &window)
{
	m_background.render(window);
	m_playButton.render(window);

}

bool SplashScreen::update(sf::RenderWindow &window)
{
	if(m_playButton.mouseHovering(window) == true)
	{
		if (m_playButton.mouseClicked(window) == true)
		{
			return true;
		}
	}
	return false;
	
}