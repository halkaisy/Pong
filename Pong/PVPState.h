#ifndef PVPSTATE_H
#define PVPSTATE_H

#include "Game.h"
#include "Gamestate.h"
#include "Paddle.h"
#include "Ball.h"

class PVPState :
	public Gamestate
{
public:
	PVPState();
	~PVPState();

	void eventHandler(Game& game);
	void update(Game& game);
	void draw(Game& game);

private:
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

