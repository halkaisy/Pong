#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gamestate.h"
#include "Menu.h"
#include "Playstate.h"
#include <memory>

class Game
{
public:
	//Konstruktor
	Game();

	enum class states { MENU, PLAY };
	void run();
	void changeState(states newstate);


	//getter und setter
	bool isRunning();
	void setRunning(bool running);
	
	sf::RenderWindow window; 
private:
	bool running;
	std::unique_ptr<Gamestate> currentState;
};

#endif
