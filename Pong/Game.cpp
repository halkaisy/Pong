/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

#include "Game.h"

Game::Game():window(sf::VideoMode(1280, 720), "Pong")
{
	running = true;
}

Game::~Game()
{
	std::cout << "Spiel entfernt" << std::endl;
}

void Game::run()
{
	// run the program as long as the window is open
	while (window.isOpen())
	{
		//zeit messen
		time2 = clock.getElapsedTime();
		timeDifference = time2 - timeStart;
		timeStart = time2;

		currentState->eventHandler(*this);

		window.clear(sf::Color::Black);
		currentState->update(*this);
		currentState->draw(*this);
		window.display();
	}
}

void Game::changeState(states newstate)
{
	switch (newstate)
	{
	case states::MENU:
		currentState = std::move(std::unique_ptr<Menu>(new Menu));
		break;
	case states::PLAY:
		currentState = std::move(std::unique_ptr<Playstate>(new Playstate));
		break;
	case states::PLAYPVP:
		currentState = std::move(std::unique_ptr<PVPState>(new PVPState));
		break;
	default:
		break;
	}
}

std::string Game::intToString(int num)
{
	std::ostringstream stringstream;
	stringstream << num;
	return stringstream.str();
}

