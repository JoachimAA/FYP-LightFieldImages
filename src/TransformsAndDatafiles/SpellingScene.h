#include "GameScene.h"




class SpellingScene : public GameScene
{
public:
	void load(int level) override;
	void handleInput(sf::Event &ev) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;

	string typeIn; // answer string that is typed in by user
	
	Button * m_checkButton;   //check button on scene


	vector<string> m_vecOfAnswers;  //stores answers to spellings

	bool m_gotCorrect = false;  //if you get the answer wrong or right 
	bool m_gotIncorrect = false;


	int numOfCorrectAnswers = 0;     //counter for correct answers

	sf::Color transparentGreen = sf::Color(0, 255, 0, 40);  //transparent green for the invisible buttons when completed

	Text * m_answer;
	Text * m_correct;  //text that is used on the screem
	Text * m_incorrect;
	Text * m_correctAnswers;
	
	


private:

};