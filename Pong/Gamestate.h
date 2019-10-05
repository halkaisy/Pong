/*
289861, Josefin Claus
295669, Haidar Alkaisy
293861, Maik Habermann
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game; //Vorwaertsdeklaration notwendig, sonst Syntaxfehler da Klasse Game unbekannt

class Gamestate {
public:
	//Abstrakte Methoden
	virtual void eventHandler(Game& game) = 0; //Soll auf events reagieren, z.B. Taste gedrueckt
	virtual void update(Game& game) = 0; //update Funktion (Ball, Paddle, Punkte)
	virtual void draw(Game& game) = 0; //Funktion um die Objekte zu zeichnen
	virtual ~Gamestate() {};

};


#endif