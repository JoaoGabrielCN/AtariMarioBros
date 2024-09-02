
/*
 * Game.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef SOURCE_GAME_H_
#define SOURCE_GAME_H_


#include "Player.h"
#include "Plataform.h"
#include "Enemy.h"
#include <vector>
using namespace std;

class Game {

private:
	void eventsLoop();
	void update();
	void draw();
	void initializeVar();


	sf::RenderWindow window;
	Player player;

	Enemy enemy;
	vector<Plataform> plataforms;

	void setPlataforms();

public:
	Game();
	void run();
};

#endif /* SOURCE_GAME_H_ */
