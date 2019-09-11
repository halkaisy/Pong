#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gamestate.h"
#include "Menu.h"
#include "Playstate.h"
#include "PVPState.h"
#include <memory>
#include <sstream>

class Game
{
public:
	//Konstruktor
	Game();

	enum class states { MENU, PLAY, PLAYPVP };
	void run();
	void changeState(states newstate);

	std::string intToString(int num);

	//getter und setter
	bool isRunning();
	void setRunning(bool running);
	
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timeStart = clock.getElapsedTime();
	sf::Time time2;
	sf::Time timeDifference;
private:
	bool running;
	std::unique_ptr<Gamestate> currentState;
};

#endif
