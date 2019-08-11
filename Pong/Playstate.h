#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "Gamestate.h"

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
	std::unique_ptr<sf::CircleShape> ball;
	std::shared_ptr<sf::RectangleShape> paddle1;
	std::shared_ptr<sf::RectangleShape> paddle2;
};

#endif