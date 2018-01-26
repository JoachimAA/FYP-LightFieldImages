#include "SplashScreen.h"



void SplashScreen::load(float sizeX , float sizeY)
{
	m_playButton.setUp(580.0f, 250.0f, 120.0f, 50.0f);
	m_background.setUp(0, 0, sizeX, sizeY, "../../TransformsAndDatafiles/assets/SplashScreenBackground.png");
}

void SplashScreen::render(sf::RenderWindow &window)
{
	m_background.render(window);
	m_playButton.render(window);

}

void SplashScreen::update(sf::RenderWindow &window)
{
	m_playButton.mouseClicked(window);
}