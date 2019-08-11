#include "Game.h"

int main()
{
	Game pong;
	pong.changeState(Game::states::MENU);
	while (pong.isRunning()) {
		pong.run();
	}

	return 0;
}