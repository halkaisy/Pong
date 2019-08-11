#include "Menu.h"

Menu::Menu()
{
	//Menupunkte initialisieren.
	font.loadFromFile("font.ttf");
	textStart.setFont(font);
	textStart.setString("Start Game");
	textStart.setCharacterSize(32);
	textStart.setPosition(500.f, 400.f);

	font.loadFromFile("font.ttf");
	textEnd.setFont(font);
	textEnd.setString("End");
	textEnd.setCharacterSize(32);
	textEnd.setPosition(500.f, 450.f);
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

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == 0)
			{
				if (startSelected)
				{
					game.changeState(Game::states::PLAY);
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
			textStart.setFillColor(sf::Color::White);
			startSelected = false;
		}
	}

	//Analog
	if (textEnd.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (textEnd.getFillColor() != sf::Color::Red) {
			textEnd.setFillColor(sf::Color::Red);
			endSelected = true;
		}
	}
	else if (!textEnd.getGlobalBounds().contains(
		sf::Mouse::getPosition(game.window).x,
		sf::Mouse::getPosition(game.window).y))
	{
		if (textEnd.getFillColor() == sf::Color::Red) {
			textEnd.setFillColor(sf::Color::White);
			endSelected = false;
		}
	}

}

void Menu::draw(Game& game)
{
	game.window.draw(textStart);
	game.window.draw(textEnd);
}
