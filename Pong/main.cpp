#include "Game.h"

int main()
{
	Game pong;

	//Spiel wird gestartet, Menu wird aufgerufen
	pong.changeState(Game::states::MENU);

	while (pong.isRunning()) 
	{
		pong.run();
	}

	return 0;
}