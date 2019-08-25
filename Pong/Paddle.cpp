#include "Paddle.h"



Paddle::Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f position, std::string texturePath)
{
	setSize(size);
	//setFillColor(color);
	setOrigin(getSize().x / 2, getSize().y /2);
	setPosition(position);

	startPosition = position;

	texture.loadFromFile(texturePath);
	texture.setSmooth(true);
	setTexture(&texture);

	speed = 1000.f;
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
