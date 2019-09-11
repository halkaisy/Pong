#include "PVPState.h"



PVPState::PVPState()
{
	paddle1 = std::make_shared<Paddle>(sf::Vector2f(64.f, 192.f), sf::Color::Blue, sf::Vector2f(32.f, 320.f), "neonPaddle.jpg");
	paddle2 = std::make_shared<Paddle>(sf::Vector2f(64.f, 192.f), sf::Color::Red, sf::Vector2f(1248.f, 320.f), "neonPaddle.jpg");
	ball = std::unique_ptr<Ball>(new Ball(20.f, sf::Color::Yellow, sf::Vector2f(640.f, 320.f), paddle1, paddle2));


	font.loadFromFile("font.ttf");

	bgTexture.loadFromFile("background.jpg");
	bgTexture.setSmooth(true);
	bgSprite.setTexture(bgTexture);

	pointsLeft = 0;
	pointsRight = 0;

	pointsLeftText.setFont(font);
	pointsLeftText.setCharacterSize(50);
	pointsLeftText.setString("0");
	pointsLeftText.setPosition(480.f, 10.f);
	pointsLeftText.setFillColor(sf::Color::Yellow);

	pointsRightText.setFont(font);
	pointsRightText.setCharacterSize(50);
	pointsRightText.setString("0");
	pointsRightText.setPosition(800.f, 10.f);
	pointsRightText.setFillColor(sf::Color::Yellow);

	paddle1->setKeyUp(sf::Keyboard::W);
	paddle1->setKeyDown(sf::Keyboard::S);
	paddle2->setKeyUp(sf::Keyboard::Up);
	paddle2->setKeyDown(sf::Keyboard::Down);

	bufferPoint.loadFromFile("point.wav");
	soundPoint.setBuffer(bufferPoint);
	soundPoint.setVolume(50);

	BGM.openFromFile("menuTheme.wav");
	BGM.setVolume(15);
	BGM.setLoop(true);
	BGM.play();
}


PVPState::~PVPState()
{
	std::cout << "PVP Spiel entfernt" << std::endl;
}

void PVPState::eventHandler(Game& game)
{
	sf::Event event;
	while (game.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			game.window.close();
			game.setRunning(false);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				ball->initialize();
			}
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				game.changeState(Game::states::MENU);
			}
		}
	}
}

void PVPState::update(Game& game)
{
	ball->update(game.window, game.timeDifference);
	paddle1->update(game.window, game.timeDifference);
	paddle2->update(game.window, game.timeDifference);


	if (ball->getPosition().x <= 0)
	{
		pointsRight++;

		soundPoint.play();
		ball->initialize();
		paddle1->initialize();
		paddle2->initialize();


	}
	else if (ball->getPosition().x >= game.window.getSize().x)
	{
		pointsLeft++;

		soundPoint.play();
		ball->initialize();
		paddle1->initialize();
		paddle2->initialize();

	}

	pointsLeftText.setString(game.intToString(pointsLeft));
	pointsRightText.setString(game.intToString(pointsRight));
}

void PVPState::draw(Game& game)
{
	game.window.draw(bgSprite);
	game.window.draw(*ball);
	game.window.draw(*paddle1);
	game.window.draw(*paddle2);
	game.window.draw(pointsLeftText);
	game.window.draw(pointsRightText);
}
