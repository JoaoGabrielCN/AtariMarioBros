#ifndef SOURCE_GAME_H_
#define SOURCE_GAME_H_

#include "Player.h"
#include "Plataform.h"
#include "Enemy.h"
#include "Pipe.h"
#include <vector>
#include <iostream>
#include "PowBlock.h"

using namespace std;

class Game {

private:

	sf::RenderWindow window; //janela do programa
	Player player; //personagem principal
	vector<Enemy> enemies;
	vector<Plataform> plataforms;
	vector<Pipe> pipes;
	PowBlock powButton;


	sf::Texture enemyTexture;
	sf::Texture plataformsTexture;
	sf::Texture floorTexture;
	sf::Texture pipeTexture;
	sf::Texture powTexture;

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
