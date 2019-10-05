/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle : public sf::RectangleShape
{
public:
	//Konstruktor
	Paddle(sf::Vector2f size, sf::Vector2f position, std::string texturePath);
	~Paddle();
	
	void update(sf::RenderWindow& window, sf::Time elapsed);
	void updateAi(sf::RenderWindow& window, sf::Time elapsed, float yBall);
	void initialize();
	void setKeyUp(sf::Keyboard::Key key);
	void setKeyDown(sf::Keyboard::Key key);
	inline void setSpeed(float speed) { this->speed = speed; }
private:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Vector2f startPosition;
	sf::Time elapsedTime;

	sf::Texture texture;

	float speed;
};

#endif