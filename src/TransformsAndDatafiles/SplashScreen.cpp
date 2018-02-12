#include "SplashScreen.h"
#include <iostream>

void SplashScreen::load()
{
	m_playButton = new Button(590.0f, 250.0f, 100.0f, 50.0f, "../../TransformsAndDatafiles/assets/Tellural.ttf" , "Play", 30.0f , sf::Color::Black);
	m_background = new Background(0, 0, 1280,720, "../../TransformsAndDatafiles/assets/SplashScreenBackground.png");
}

void SplashScreen::render(sf::RenderWindow &window)
{
	m_background->render(window);
	m_playButton->render(window);
	m_playButton->m_buttonText->render(window);

}

bool SplashScreen::update(sf::RenderWindow &window)
{
	if(m_playButton->mouseHovering(window) == true)
	{
		if (m_playButton->mouseClicked(window) == true)
		{
			return true;
		}
	}
	return false;
	
}