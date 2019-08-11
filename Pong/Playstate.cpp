#include "Playstate.h"



Playstate::Playstate()
{
	paddle1 = std::make_shared<sf::RectangleShape>(sf::Vector2f(64.f, 192.f));
	paddle2 = std::make_shared<sf::RectangleShape>(sf::Vector2f(64.f, 192.f));
	ball = std::unique_ptr<sf::CircleShape>(new sf::CircleShape(20));

	paddle1->setPosition(0.f, 300.f);
	paddle2->setPosition(1214.f, 300.f);



}


Playstate::~Playstate()
{
	std::cout << "Spiel entfernt" << std::endl;
}

void Playstate::eventHandler(Game& game)
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

void Playstate::update(Game& game)
{
}

void Playstate::draw(Game& game)
{
	game.window.draw(*ball);
	game.window.draw(*paddle1);
	game.window.draw(*paddle2);
}
