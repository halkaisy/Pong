/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

#include "Paddle.h"

Paddle::Paddle(sf::Vector2f size, sf::Vector2f position, std::string texturePath)
{
	setSize(size);
	setOrigin(getSize().x / 2, getSize().y /2);
	setPosition(position);

	startPosition = position;

	//Textur laden vom angegebenen path, Moeglichkeit verschiedene Sprites fuer Paddles zu verwenden
	texture.loadFromFile(texturePath);
	texture.setSmooth(true);
	setTexture(&texture);

	speed = 600.f;
	up = sf::Keyboard::Key::Up;
	down = sf::Keyboard::Key::Down;
}

Paddle::~Paddle()
{
	std::cout << "Paddle entfernt\n";
}


void Paddle::update(sf::RenderWindow& window, sf::Time elapsed)
{
	elapsedTime += elapsed;

	if (sf::Keyboard::isKeyPressed(up) && getPosition().y > getGlobalBounds().height / 2)
	{
		move(sf::Vector2f(0.f, -speed * elapsed.asSeconds()));
	}
	else if (sf::Keyboard::isKeyPressed(down) && getPosition().y < window.getSize().y - getGlobalBounds().height / 2)
	{
			move(sf::Vector2f(0.f, speed * elapsed.asSeconds()));
	};
}

void Paddle::updateAi(sf::RenderWindow& window, sf::Time elapsed, float yBall)
{
	setSpeed(350);
	elapsedTime += elapsed;

	//Ist Y-Koordinate vom Ball kleiner als vom Paddle, heisst dass das der Ball ueber dem Paddle ist -> Paddle muss sich nach oben bewegen
	if (yBall < (getPosition().y) && getPosition().y > getGlobalBounds().height / 2)
	{
		move(sf::Vector2f(0.f, -speed * elapsed.asSeconds()));
	}
	//Y-Koordinate von Ball groesser als von Paddle -> Paddle muss nach unten
	else if (yBall > (getPosition().y) && getPosition().y < window.getSize().y - getGlobalBounds().height / 2)
	{
		move(sf::Vector2f(0.f, speed * elapsed.asSeconds()));
	}
	else
	{
		//Sind Ball und Paddle auf gleicher Hoehe, so bewegt sich der Paddle nicht.
		move(sf::Vector2f(0.f, 0.f));
	}
}

void Paddle::initialize()
{
	setPosition(startPosition);
}

void Paddle::setKeyUp(sf::Keyboard::Key key)
{
	up = key;
}

void Paddle::setKeyDown(sf::Keyboard::Key key)
{
	down = key;
}
