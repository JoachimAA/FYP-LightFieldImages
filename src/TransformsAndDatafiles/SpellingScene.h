#include "GameScene.h"



class SpellingScene : public GameScene
{
public:
	void load(int level) override;
	void handleInput(sf::Event &ev) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;

	Button * m_checkButton;

	vector<string> vecOfAnswers;

	Text * answer;
	string typeIn;

private:

};