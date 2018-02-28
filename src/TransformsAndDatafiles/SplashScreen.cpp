#include "SplashScreen.h"
#include <iostream>

void SplashScreen::load(int level)
{
	m_spellingButton = new Button(570.0f, 250.0f, 140.0f, 50.0f, "../../TransformsAndDatafiles/assets/Tellural.ttf" , "Spelling", 30.0f , sf::Color::Black);
	m_alphabetButton = new Button(560.0f, 350.0f, 160.0f, 50.0f, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Alphabet", 30.0f, sf::Color::Black);
	m_background = new Background(0, 0, 1280,720, "../../TransformsAndDatafiles/assets/SplashScreenBackground.png");
}

void SplashScreen::render(sf::RenderWindow &window)
{
	//render background
	m_background->render(window);

	//render buttons and text that goes with each button
	m_spellingButton->render(window);
	m_spellingButton->m_buttonText->render(window);
	m_alphabetButton->render(window);
	m_alphabetButton->m_buttonText->render(window);

}

int SplashScreen::update(sf::RenderWindow &window, sf::Clock &gameClock)
{

	//checks button for mouse hoveing over and then clicking
	if(m_spellingButton->mouseHovering(window) == true)
	{
		if (m_spellingButton->mouseClicked(window) == true)
		{
			return 1;
		}
	}

	if (m_alphabetButton->mouseHovering(window) == true)
	{
		if (m_alphabetButton->mouseClicked(window) == true)
		{
			return 2;
		}
	}
	return 0;
	
}

void SplashScreen::handleInput(sf::Event & ev)
{
}

