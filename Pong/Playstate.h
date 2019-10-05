#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "Gamestate.h"
#include "Paddle.h"
/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

#include "Ball.h"

class Playstate :
	public Gamestate
{
public:
	//Konstruktor und Destruktor
	Playstate();
	~Playstate();

	//Implementieren der abstrakten Funktionen
	void eventHandler(Game& game);
	void update(Game& game);
	void draw(Game& game);

private:
	//Membervariablen fuer die Objekte
	std::unique_ptr<Ball> ball;
	std::shared_ptr<Paddle> paddle1;
	std::shared_ptr<Paddle> paddle2;

	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	sf::Font font;
	sf::Text pointsLeftText;
	sf::Text pointsRightText;

	sf::SoundBuffer bufferPoint;
	sf::Sound soundPoint;

	sf::Music BGM;

	int pointsLeft;
	int pointsRight;
};

#endif