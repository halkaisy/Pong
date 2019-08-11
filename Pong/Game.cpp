#include "Game.h"

Game::Game():window(sf::VideoMode(1280, 720), "Pong")
{
	running = true;

	//Unique Pointer auf Menu
	currentState = std::move(std::unique_ptr<Menu>(new Menu));
}

void Game::run()
{
	// run the program as long as the window is open
	while (window.isOpen())
	{
		currentState->eventHandler(*this);

		window.clear(sf::Color::Black);
		currentState->update(*this);
		currentState->draw(*this);
		window.display();
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
