/*
 * Game.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef GAME_H_
#define GAME_H_

#include<SFML/Graphics.hpp>
#include "Player.h"
#include "Plataform.h"
#include <vector>
using namespace std;

class Game {

private:
	void eventsLoop();
	void update();
	void draw();
	void initializeVar();
	void setPlataforms();
	sf::RenderWindow window;
	Player player;
	Plataform floor;

	vector<Plataform> plataforms;

public:
	Game();
	void run();
};

#endif /* GAME_H_ */
