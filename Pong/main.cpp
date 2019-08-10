#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");
	window.setFramerateLimit(60);
	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString("Pong");
	// set the character size
	text.setCharacterSize(48); // in pixels, not points!
	// set the color
	text.setFillColor(sf::Color::Red);

	text.setPosition(600, 300);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(text);
		window.display();
	}

	return 0;
}