/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

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
	~Game();

	enum class states { MENU, PLAY, PLAYPVP };
	void run();

	//Funktion zur Umwandlung von int zu String (Verwendung bei Anzeige der Punkte)
	std::string intToString(int num);

	//getter und setter
	inline bool isRunning() { return running; }
	inline void setRunning(bool running) { this->running = running; }
	//setter fuer currentstate
	void changeState(states newstate);

	//Membervariablen
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
