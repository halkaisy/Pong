#include "Paddle.h"



Paddle::Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
	setSize(size);
	setFillColor(color);
	setOrigin(getSize().x / 2, getSize().y /2);
	setPosition(position);

	startPosition = position;
}


void Paddle::update(sf::RenderWindow& window, sf::Time elapsed)
{
	//elapsedTime += elapsed;

	if (sf::Keyboard::isKeyPressed(up) && getPosition().y > getGlobalBounds().height / 2)
	{
		move(sf::Vector2f(0.f, -1000.f * elapsed.asSeconds()));
	}
	else if (sf::Keyboard::isKeyPressed(down) && getPosition().y < window.getSize().y - getGlobalBounds().height / 2)
	{
			move(sf::Vector2f(0.f, 1000.f * elapsed.asSeconds()));
	};
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
