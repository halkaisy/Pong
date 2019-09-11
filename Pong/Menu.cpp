#include "Menu.h"

Menu::Menu()
{
	//Menupunkte initialisieren.
	font.loadFromFile("font.ttf");
	textStart.setFont(font);
	textStart.setString("Start Game");
	textStart.setCharacterSize(32);
	textStart.setFillColor(sf::Color::Green);
	textStart.setPosition(500.f, 200.f);

	pvpStart.setFont(font);
	pvpStart.setString("PVP Start");
	pvpStart.setCharacterSize(32);
	pvpStart.setFillColor(sf::Color::Green);
	pvpStart.setPosition(500.f, 250.f);

	textEnd.setFont(font);
	textEnd.setString("End");
	textEnd.setCharacterSize(32);
	textEnd.setFillColor(sf::Color::Green);
	textEnd.setPosition(500.f, 300.f);

	//warnung uninitialized member variables
	startSelected = false;
	pvpStartSelected = false;
	endSelected = false;

	//Hintergrund erstellen
	texture.loadFromFile("background.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);

	//Benutzerinformationen / Beschreibung
	font.loadFromFile("font.ttf");
	description.setFont(font);
	description.setString("CONTROLS\n\n"
		"Player1	 W	 S \n"
		"Player2	UP	DOWN \n"
		"Space	Start Ball\n"
		"Esc	Return to Menu");
	description.setCharacterSize(12);
	description.setFillColor(sf::Color::Yellow);
	description.setPosition(500.f, 400.f);
	//Sound mouseclick
	bufferMouseClick.loadFromFile("mouseClick.wav");
	soundMouseClick.setBuffer(bufferMouseClick);
	//BGM erstellen und abspielen
	soundMenu.openFromFile("menuTheme.wav");
	soundMenu.setVolume(20);
	soundMenu.setLoop(true);
	soundMenu.play();
}

Menu::~Menu()
{
	std::cout << "Menu entfernt" << std::endl;
}

void Menu::eventHandler(Game& game)
{
	//Fenster bleibt solange offen, bis der Benutzer es schliesst.
	sf::Event event;
	while (game.window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			game.window.close();
			game.setRunning(false);
		}
		//Gamestate aendern, wenn ein Menupunkt ausgewaehlt wurde
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == 0)
			{
				if (startSelected)
				{
					soundMouseClick.play();
					game.changeState(Game::states::PLAY);
				}
				else if (pvpStartSelected)
				{
					soundMouseClick.play();
					game.changeState(Game::states::PLAYPVP);
				}
				else if (endSelected)
				{
					game.window.close();
					game.setRunning(false);
				}
			}
		}
	}
}

void Menu::update(Game& game)
{
	//Pruefe, ob der Menupunkt die Maus auf dem Menupunkt ist.
	if (textStart.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		//Farblich kenntlich machen, dass Menupunkt ausgewaehlt wird
		if (textStart.getFillColor() != sf::Color::Red) {
			textStart.setFillColor(sf::Color::Red);
			startSelected = true;
		}
	}
	//Wenn Maus nicht mehr auf dem Menupunkt ist, wird die Farbe zurueckgesetzt.
	else if (!textStart.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (textStart.getFillColor() == sf::Color::Red) {
			textStart.setFillColor(sf::Color::Green);
			startSelected = false;
		}
	}
	//Analog
	if (pvpStart.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (pvpStart.getFillColor() != sf::Color::Red)
		{
			pvpStart.setFillColor(sf::Color::Red);
			pvpStartSelected = true;
		}
	}
	else if (!pvpStart.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (pvpStart.getFillColor() == sf::Color::Red)
		{
			pvpStart.setFillColor(sf::Color::Green);
			pvpStartSelected = false;
		}
	}

	//Analog
	if (textEnd.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (textEnd.getFillColor() != sf::Color::Red) 
		{
			textEnd.setFillColor(sf::Color::Red);
			endSelected = true;
		}
	}
	else if (!textEnd.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (textEnd.getFillColor() == sf::Color::Red) 
		{
			textEnd.setFillColor(sf::Color::Green);
			endSelected = false;
		}
	}

}

void Menu::draw(Game& game)
{
	game.window.draw(sprite);
	game.window.draw(textStart);
	game.window.draw(pvpStart);
	game.window.draw(description);
	game.window.draw(textEnd);
}