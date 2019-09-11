#ifndef MENU_H
#define MENU_H


#include "Game.h"

class Menu :public Gamestate {
public:
	Menu();
	~Menu();
	void eventHandler(Game& game);
	void update(Game& game);
	void draw(Game& game);
private:
	bool startSelected;
	bool pvpStartSelected;
	bool endSelected;
	sf::Font font;
	sf::Text textStart;
	sf::Text pvpStart;
	sf::Text description;
	sf::Text textEnd;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::SoundBuffer bufferMouseClick;
	sf::Sound soundMouseClick;
	sf::Music soundMenu;
};

#endif