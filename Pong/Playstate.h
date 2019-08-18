#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "Gamestate.h"
#include "Paddle.h"
#include "Ball.h"

class Playstate :
	public Gamestate
{
public:
	Playstate();
	~Playstate();

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

	int pointsLeft;
	int pointsRight;
};

#endif