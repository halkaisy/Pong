#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gamestate.h"
#include "Menu.h"
#include <memory>

class Game
{
public:
	//Konstruktor
	Game();

	void run();

	//getter und setter
	bool isRunning();
	void setRunning(bool running);
	
	sf::RenderWindow window; 
private:
	bool running;
	std::unique_ptr<Gamestate> currentState;
};

#endif
