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
#include "Pipe.h"
#include <vector>
#include <iostream>
using namespace std;

class Game {

private:

	sf::RenderWindow window; //janela do programa
	Player player; //personagem principal
	vector<Enemy> enemies;
	vector<Plataform> plataforms;
	vector<Pipe> pipes;



	sf::Texture enemyTexture;
	sf::Texture plataformsTexture;
	sf::Texture floorTexture;
	sf::Texture pipeTexture;

	bool pause();
	void eventsLoop();
	void update();
	void draw();
	void initializeVar();
	void setPlataforms();
	void setEnemies();
	void setPipes();

public:
	Game();
	void run();
};

#endif /* SOURCE_GAME_H_ */
