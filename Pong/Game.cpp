#include "Game.h"

Game::Game():window(sf::VideoMode(1280, 720), "Pong")
{
	running = true;
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
	default:
		break;
	}
}


bool Game::isRunning()
{
	return running;
}

void Game::setRunning(bool running)
{
	this->running = running;
}
