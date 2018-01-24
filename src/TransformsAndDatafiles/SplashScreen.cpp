#include "SplashScreen.h"



void SplashScreen::load()
{
	m_playButton->setUp(580.0f, 250.0f, 120.0f, 50.0f);
}

void SplashScreen::render(sf::RenderWindow &window)
{
	m_playButton->render(window);
}

void SplashScreen::update(sf::RenderWindow &window)
{
	m_playButton->mouseClicked(window);
}