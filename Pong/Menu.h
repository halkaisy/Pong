/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

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
	//bool true wenn ein Textfeld durch die Maus ausgewaehlt ist, sonst false
	bool startSelected;
	bool pvpStartSelected;
	bool endSelected;

	//Membervariablen fuer Texte, Fonts, Sounds, Musik...
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