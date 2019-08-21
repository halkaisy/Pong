#ifndef BALL_H
#define BALL_H

#include "Paddle.h"
#include <memory>
#include <SFML/Audio.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(float radius, sf::Color color, sf::Vector2f position, std::shared_ptr<Paddle> paddle1, std::shared_ptr<Paddle> paddle2);
	void initialize();
	void update(sf::RenderWindow& window, sf::Time elapsed);


private:
	int direcition;
	float speed;
	sf::Vector2f movement;
	sf::Texture textur;

	sf::SoundBuffer bufferWall;
	sf::Sound soundWall;
	sf::SoundBuffer bufferPaddle;
	sf::Sound soundPaddle;

	std::shared_ptr<Paddle> pPaddle1;
	std::shared_ptr<Paddle> pPaddle2;
};

#endif