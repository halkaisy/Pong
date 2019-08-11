#include "Playstate.h"



Playstate::Playstate()
{
	paddle1 = std::make_shared<Paddle>(sf::Vector2f(64.f, 192.f), sf::Color::Blue, sf::Vector2f(32.f, 320.f));
	paddle2 = std::make_shared<Paddle>(sf::Vector2f(64.f, 192.f), sf::Color::Red, sf::Vector2f(1248.f, 320.f));
	ball = std::unique_ptr<sf::CircleShape>(new sf::CircleShape(20));

	paddle1->setKeyUp(sf::Keyboard::W);
	paddle1->setKeyDown(sf::Keyboard::S);
	paddle2->setKeyUp(sf::Keyboard::Up);
	paddle2->setKeyDown(sf::Keyboard::Down);

}


Playstate::~Playstate()
{
	std::cout << "Spiel entfernt" << std::endl;
}

void Playstate::eventHandler(Game & game)
{
	sf::Event event;
	while (game.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			game.window.close();
			game.setRunning(false);
		}
	}
}

void Playstate::update(Game & game)
{
	paddle1->update(game.window, game.timeDifference);
	paddle2->update(game.window, game.timeDifference);
}

void Playstate::draw(Game& game)
{
	game.window.draw(*ball);
	game.window.draw(*paddle1);
	game.window.draw(*paddle2);
}
