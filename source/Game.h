#ifndef SOURCE_GAME_H_
#define SOURCE_GAME_H_

#include "Player.h"
#include "Plataform.h"
#include "Enemy.h"
#include "Pipe.h"
#include <vector>
#include <iostream>
#include "PowBlock.h"
#include <SFML/Audio.hpp>

using namespace std;

class Game {

private:

	sf::RenderWindow window; //janela do programa
	Player player; //personagem principal
	vector<Enemy> enemies;
	vector<Plataform> plataforms;
	vector<Pipe> pipes;
	PowBlock powButton;
	bool playSound;

	sf::Texture enemyTexture;
	sf::Texture plataformsTexture;
	sf::Texture floorTexture;
	sf::Texture pipeTexture;
	sf::Texture powTexture;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Music theme;
	sf::SoundBuffer bufferPow;
	sf::Sound powSound;
	sf::SoundBuffer bufferResult;
	sf::Sound resultSound;
	sf::Music resultMusic;

	sf::Font font;
	sf::Text gameOverText;
	sf::RectangleShape restartButton;
	sf::Text restartButtonText;
	sf::Text result;

	bool pause();
	void eventsLoop();
	void update();
	void draw();
	void initializeVar();
	void setPlataforms();
	void setEnemies();
	void setPipes();
	void setTextures();
	void setSounds();
	void drawGameOver();
	void testRestartClick();
	void resetGame();
	void setTexts();

	;

public:
	Game();
	void run();
};

#endif /* SOURCE_GAME_H_ */
