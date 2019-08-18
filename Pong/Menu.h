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
	bool endSelected;
	sf::Font font;
	sf::Text textStart;
	sf::Text textEnd;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif