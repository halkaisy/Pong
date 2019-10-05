/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

#include "Ball.h"


Ball::Ball(float radius, sf::Vector2f position, std::shared_ptr<Paddle> paddle1, std::shared_ptr<Paddle> paddle2)
{
	setRadius(radius);
	//Origin auf Mittelpunkt setzen
	setOrigin(getRadius() / 2, getRadius() / 2);
	setPosition(position);

	pPaddle1 = paddle1;
	pPaddle2 = paddle2;

	//direction und speed mit Startwerten initialisieren
	direcition = 1;
	speed = 0.f;

	//Movement zu Beginn 0
	movement = sf::Vector2f(0.f, 0.f);

	//Textur fuer den Ball
	textur.loadFromFile("ball.png");
	textur.setSmooth(true);
	setTexture(&textur);

	//Sounds bei Kollision mit Waenden oder Paddles
	bufferWall.loadFromFile("pongPaddle.wav");
	soundWall.setBuffer(bufferWall);
	bufferPaddle.loadFromFile("pongWall.wav");
	soundPaddle.setBuffer(bufferPaddle);


}

Ball::~Ball()
{
	std::cout << "Ball entfernt" << std::endl;
}

void Ball::initialize()
{
	speed = 300.f;
	direcition = rand() % 4;

	//Ball bekommt eine zufaellige startrichtung
	switch (Ball::direcition)
	{
	case 0:
		movement = sf::Vector2f(speed, speed);
		break;
	case 1:
		movement = sf::Vector2f(speed, -speed);
		break;
	case 2:
		movement = sf::Vector2f(-speed, speed);
		break;
	case 3:
		movement = sf::Vector2f(-speed, -speed);
		break;
	default:
		break;
	}

	setPosition(640.f, 320.f);
}

void Ball::update(sf::RenderWindow & window, sf::Time elapsed)
{
	//Auf Kollision mit Bildschirmrand oben und unten pruefen

	if (getPosition().y <= 0)
	{
		soundWall.play();
		movement.y = speed;
	}
	else if (getPosition().y >= window.getSize().y)
	{
		soundWall.play();
		movement.y = -speed;
	}


	//Kollision mit Paddle
	if (getGlobalBounds().left < pPaddle1->getPosition().x + (pPaddle1->getSize().x / 2) &&
		getGlobalBounds().left + getGlobalBounds().width > pPaddle1->getPosition().x - (pPaddle1->getSize().x / 2) &&
		getGlobalBounds().top + getGlobalBounds().height >= pPaddle1->getPosition().y - pPaddle1->getSize().y / 2 &&
		getGlobalBounds().top <= pPaddle1->getPosition().y + pPaddle1->getSize().y / 2)
	{
		soundPaddle.play();
		movement.x = speed;
		/*
		//Ball kollidiert oben, unten oder mittig mit paddle?
		if (getPosition().y < pPaddle1->getPosition().y)
		{
			movement.x = speed;
			movement.y = -speed;
		}
		else if (getPosition().y > pPaddle1->getPosition().y)
		{
			movement.x = speed;
			movement.y = speed;
		}
		else
		{
			movement.x = speed;
		}*/
	}
	//Kollisiion Paddle2
	else if (getGlobalBounds().left < pPaddle2->getPosition().x + (pPaddle2->getSize().x / 2) &&
		getGlobalBounds().left + getGlobalBounds().width > pPaddle2->getPosition().x - (pPaddle2->getSize().x / 2) &&
		getGlobalBounds().top + getGlobalBounds().height >= pPaddle2->getPosition().y - pPaddle2->getSize().y / 2 &&
		getGlobalBounds().top <= pPaddle2->getPosition().y + pPaddle2->getSize().y / 2)
	{

		soundPaddle.play();
		movement.x = -speed;
		/*
		//Ball kollidiert oben, unten oder mittig mit paddle?
		if (getPosition().y < pPaddle2->getPosition().y)
		{
			movement.x = -speed;
			movement.y = -speed;
		}
		else if (getPosition().y > pPaddle2->getPosition().y)
		{
			movement.x = -speed;
			movement.y = speed;
		}
		else
		{
		   movement.x = -speed;
		}*/
	}

	move(movement.x * elapsed.asSeconds(), movement.y * elapsed.asSeconds());

	//Ball mit fortschreitender Zeit beschleunigen
	speed = speed + elapsed.asSeconds() * 10;
}
