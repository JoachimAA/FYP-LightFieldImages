#include "PracticeScene.h"

void PracticeScene::load(int level)
{
	//reading files and loading and storing 
	file.open("../../TransformsAndDatafiles/Assets/practiceLevel" + std::to_string(level) + ".txt");
	if (file.is_open())
	{
		//sounds
		std::getline(file, s);  //getting first line
		ss.str(s);   //store in string stream
		ss >> m_numOfSounds;  //equals number of sounds
		ss.clear();  //clear string stream
		for (int i = 0; i < m_numOfSounds; i++){
			std::getline(file, s);  //get next line
			m_vecOfSounds.push_back(s);  //add to vector of sounds
		}
		//hints
		for (int i = 0; i < m_numOfSounds; i++){
			getline(file, s);
			m_vecOfHints.push_back(s);
		}
		//backgrounds
		for (int i = 0; i < m_numOfSounds; i++){
	     	getline(file, s);
			m_background = new Background(0, 0, 1280, 720, s);
			m_vecOfBackgrounds.push_back(m_background);
		}
		//buttons
		m_currentBackground = 0; //setting the background number
		for (int i = 0; i < m_numOfSounds; i++){
			float xPos, yPos, xSize, ySize;
			getline(file, s);
			ss.str(s);
			ss >> xPos;
			ss.clear();
			getline(file, s);
			ss.str(s);
			ss >> yPos;
			ss.clear();
			getline(file, s);
			ss.str(s);
			ss >> xSize;
			ss.clear();
			getline(file, s);
			ss.str(s);
			ss >> ySize;
			ss.clear();
			m_iButton = new InvisibleButton(xPos, yPos, xSize, ySize);
			m_vecOfIButtons.push_back(m_iButton);
		}
	}
	else {
		std::cout << "cannot open sound file" << endl;
	}
	file.close();

	//back to menu button
	m_menuButton = new Button(20, 10, 225, 50, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Back to Menus", 30, sf::Color::Black);
	m_hints = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", m_vecOfHints[0], 100, sf::Color::Green, 270.0f, -15.0f);

	for (int i = 0; i < m_numOfSounds; i++){
		sceneSoundManager.loadSound(m_vecOfSounds[i]);
	}

	//back and forth from levels arrows
	if (level < 4) { //number of levels
		m_nextLevel = new TexturedButton(1190.0f, 340.0f, 0.13f, 0.13f, "../../TransformsAndDatafiles/assets/arrow.png");
		m_lastLevel = false;
	}
	if (level > 1) {
		m_previousLevel = new TexturedButton(10.0f, 340.0f, 0.13f, 0.13f, "../../TransformsAndDatafiles/assets/arrow.png");
		m_previousLevel->rotateSprite(180.0f);
		m_firstLevel = false;
	}

}

void PracticeScene::render(sf::RenderWindow & window)
{
	
	    m_vecOfBackgrounds[m_currentBackground]->render(window);   //rendering background and buttons 
		m_menuButton->render(window);
		m_menuButton->m_buttonText->render(window);

		if (m_lastLevel == false) {
			m_nextLevel->renderSprite(window);  //render next level arrow
		};
		if (m_firstLevel == false) {
			m_previousLevel->renderSprite(window);  //render previous level arrow
		};

		//if i need to render the buttons  selected object button is not rendered
		for (int i = 0; i < m_numOfSounds; i++){
			if (i != m_currentBackground){
				m_vecOfIButtons[i]->render(window);
			}
		}
		//display the hint answer
		if (m_displayHint == true){
			m_hints->setMessage(m_vecOfHints[m_currentBackground]);
			m_hints->render(window);
		}
	
}
//update 
	int PracticeScene::update(sf::RenderWindow & window, sf::Clock &gameClock)
	{
		sf::Time elapsedTime = gameClock.getElapsedTime();  //get elapsed time
		if (elapsedTime.asSeconds() > 0.2f) { //delay so buttons cant be pressed instantly
			if (m_menuButton->mouseHovering(window) == true) {  //checks if being hovered over
				if (m_menuButton->mouseClicked(window) == true) {  //checks for click
					return 1;
				}
			}
			if (m_firstLevel == false) {  //goes back a level
				if (m_previousLevel->mouseHovering(window) == true) {
					if (m_previousLevel->mouseClicked(window) == true) {
						return 5;
					}
				}
			}
			if (m_lastLevel == false) {  //goes forward a level
				if (m_nextLevel->mouseHovering(window) == true) {
					if (m_nextLevel->mouseClicked(window) == true) {
						return 4;
					}
				}
			}  //checks invisible object buttons 
			for (int i = 0; i < m_numOfSounds; i++) {
				if (m_vecOfIButtons[i]->mouseHovering(window) == true) {
					if (m_vecOfIButtons[i]->mouseClicked(window) == true) {
						gameClock.restart();  //restarts clock
						m_displayHint = true;
						m_currentBackground = i;  //changes background
						sceneSoundManager.playSound(i);  //plays sound
					}
				}

			}
		}
	return 0;
}


void PracticeScene::handleInput(sf::Event & ev)
{
}
