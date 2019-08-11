#include "Game.h"

int main()
{
	Game pong;

	while (pong.isRunning()) {
		pong.run();
	}

	return 0;
}