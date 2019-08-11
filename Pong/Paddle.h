#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle : public sf::RectangleShape
{
public:
	Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f position);
	
	void update(sf::RenderWindow& window, sf::Time elapsed);
	void initialize();
	void setKeyUp(sf::Keyboard::Key key);
	void setKeyDown(sf::Keyboard::Key key);

private:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Vector2f startPosition;
	sf::Time elapsedTime;
};

#endif