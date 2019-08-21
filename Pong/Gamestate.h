#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game; //Vorwaertsdeklaration

class Gamestate {
public:
	//Abstrakte Methoden
	virtual void eventHandler(Game& game) = 0;
	virtual void update(Game& game) = 0;
	virtual void draw(Game& game) = 0;
	virtual ~Gamestate() {};

};


#endif