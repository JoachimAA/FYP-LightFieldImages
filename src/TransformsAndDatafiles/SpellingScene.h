#include "GameScene.h"



class SpellingScene : public GameScene
{
public:
	void load(int level) override;
	void handleInput(sf::Event &ev) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;

	string typeIn;
	
	Button * m_checkButton;

	vector<string> vecOfAnswers;

	bool gotCorrect = false;
	bool gotIncorrect = false;

	sf::Color transparentGreen = sf::Color(0, 255, 0, 40);

	Text * answer;
	Text * correct;
	Text * incorrect;
	
	


private:

};