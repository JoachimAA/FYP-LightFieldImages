#include "SpellingScene.h"


void SpellingScene::load(int level)
{
//reading sound files
file.open("../../TransformsAndDatafiles/Assets/spellingLevel" + std::to_string(level) + ".txt");
if (file.is_open()) {

	// 1 Sound effect obtained from https ://www.zapsplat.com
	std::getline(file, s);
	ss.str(s);
	ss >> m_numOfSounds;
	ss.clear();
	for (int i = 0; i < m_numOfSounds + 1; i++) {
		std::getline(file, s);
		m_vecOfSounds.push_back(s);
	}
	//backgrounds
	for (int i = 0; i < m_numOfSounds; i++) {
		getline(file, s);
		m_background = new Background(0, 0, 1280, 720, s);
		m_vecOfBackgrounds.push_back(m_background);
	}

	//answers
	for (int i = 0; i < m_numOfSounds * 2; i++) {
		getline(file, s);
		m_vecOfAnswers.push_back(s);
	}
	m_currentBackground = 0; //setting the background number

	//buttons
	for (int i = 0; i < m_numOfSounds; i++) {
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
//loads sounds
for (int i = 0; i < m_numOfSounds + 1; i++) {
	sceneSoundManager.loadSound(m_vecOfSounds[i]);

}

//back to menu button
m_menuButton = new Button(20.0f, 10.0f, 225.0f, 50.0f, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Back to Menus", 30, sf::Color::Black);
//check answer button
m_checkButton = new Button(20.0f, 70.0f, 225.0f, 50.0f, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Check answer", 30, sf::Color::Black);
// arrow button for next level
if (level < 4) {
	m_nextLevel = new TexturedButton(1190.0f, 340.0f, 0.13f, 0.13f, "../../TransformsAndDatafiles/assets/arrow.png");
	m_lastLevel = false;
}
if (level > 1) {
	m_previousLevel = new TexturedButton(10.0f, 340.0f, 0.13f, 0.13f, "../../TransformsAndDatafiles/assets/arrow.png");
	m_previousLevel->rotateSprite(180.0f);
	m_firstLevel = false;
}
//answer typing spot
m_answer = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", "", 50, sf::Color::Black, 370.0f, 0.0f);

m_correct = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", "Correct!", 150, sf::Color::Green, 370.0f, 200.0f);
m_incorrect = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", "Incorrect Try Again", 100, sf::Color::Red, 200.0f, 200.0f);
m_correctAnswers = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", std::to_string(numOfCorrectAnswers) + "/" + std::to_string(m_numOfSounds), 50, sf::Color::Black , 270.0f, 0.0f);
}


//render scene
void SpellingScene::render(sf::RenderWindow & window)
{
	//renders current background
	m_vecOfBackgrounds[m_currentBackground]->render(window);
	//if i need to render the buttons
	for (int i = 0; i < m_numOfSounds; i++)
	{
		if (i != m_currentBackground)
		{
			m_vecOfIButtons[i]->render(window);
		}
	}

	m_menuButton->render(window);
	m_menuButton->m_buttonText->render(window);
	m_checkButton->render(window);
	m_checkButton->m_buttonText->render(window);

	//render go forward a level
	if (m_lastLevel == false && numOfCorrectAnswers == m_numOfSounds) {
		m_nextLevel->renderSprite(window);
	}
	//amount of answers correct
	m_correctAnswers->render(window);

	//render go back a level
	if (m_firstLevel == false) {
		m_previousLevel->renderSprite(window);
	}
	//if wrong answer or correct answer render text
	m_answer->render(window);
	if (m_gotCorrect == true) {
		m_correct->render(window);
	}
	if (m_gotIncorrect == true){
		m_incorrect->render(window);
}

	
}

int SpellingScene::update(sf::RenderWindow & window, sf::Clock &gameClock)
{
	sf::Time elapsedTime = gameClock.getElapsedTime();  //get elapsed time
	if (elapsedTime.asSeconds() > 0.2f) {
		
		//goes forward a level
		if (numOfCorrectAnswers == m_numOfSounds){
			m_correctAnswers->m_text.setColor(sf::Color::Green);
			if (m_lastLevel == false) {
				if (m_nextLevel->mouseHovering(window) == true)
				{
					if (m_nextLevel->mouseClicked(window) == true)
					{
						return 4;
					}
				}
			}
		}
		//goes back a level
		if (m_firstLevel == false) {
			if (m_previousLevel->mouseHovering(window) == true)
			{
				if (m_previousLevel->mouseClicked(window) == true)
				{
					return 5;
				}
			}
		}
		//return to menu button

		if (m_menuButton->mouseHovering(window) == true)
		{
			if (m_menuButton->mouseClicked(window) == true)
			{
				return 1;
			}
		}

		//plays sound
		for (int i = 0; i < m_numOfSounds; i++)
			if (m_vecOfIButtons[i]->mouseHovering(window) == true)
			{
				if (m_vecOfIButtons[i]->mouseClicked(window) == true)
				{
					m_currentBackground = i;  //sets the new background
					sceneSoundManager.playSound(i); //plays sound for that background
					typeIn.clear();   //clear the type in string
					m_answer->setMessage(typeIn);  //set the type in bar to empty
				}
			}


		
		//check button
		if (elapsedTime.asSeconds() > 1) {  //resets the correct and incorrect message so it disappears
			m_gotCorrect = false;
			m_gotIncorrect = false;
			if (m_checkButton->mouseHovering(window) == true) {  //check mouse is hovering 
				if (m_checkButton->mouseClicked(window) == true) { //check mouse is clicking on button
					for (int i = 0; i < 2; i++) { //loop twice
						if (typeIn == m_vecOfAnswers[m_currentBackground * 2 + i]) { //check the answers
							gameClock.restart(); // restart clock
							m_gotCorrect = true;
							m_gotIncorrect = false;
							if (m_vecOfIButtons[m_currentBackground]->m_rectangle.getFillColor() != transparentGreen) {//if answer hasnt been gotten correct before
								m_vecOfIButtons[m_currentBackground]->m_rectangle.setFillColor(transparentGreen);  //change to green
								numOfCorrectAnswers++; //add counter of correct answers
								m_correctAnswers->setMessage(std::to_string(numOfCorrectAnswers) + "/" + std::to_string(m_numOfSounds));  //updates string for counter
								sceneSoundManager.playSound(m_numOfSounds);  //play sound effect
							}
							return 0;
						}
						else {
							gameClock.restart();
							m_gotIncorrect = true;
						}
					}
				}
			}
		}
	}
	return 0;
}


void SpellingScene::handleInput(sf::Event & ev)
{
	
	if (ev.text.unicode < 127 && ev.text.unicode > 31)   // if it is a letter on the keyboard between the two unicode values
	{
		typeIn += static_cast<char>(ev.text.unicode);  //add the character pressed to the typein string
		m_answer->setMessage(typeIn);  // new answer is the type in
	}
    if (ev.text.unicode == '\b') {  //if you press backspace
		if (typeIn.size() == 1) {  //solves edge case of backspace pressed when string length is 0
			typeIn.erase();
			m_answer->setMessage(typeIn);
		}
		if (typeIn.size() > 1) {  //size of answer is bigger than 1 
				typeIn.erase(typeIn.size() - 1, 1);  //erase the last two by two because the backspace is registered as a spot by the string
				m_answer->setMessage(typeIn); //new answer is the type in
		}

	}
}
