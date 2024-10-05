#ifndef SOURCE_PLAYER_H_
#define SOURCE_PLAYER_H_

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Plataform.h"
#include "Enemy.h"


class Enemy;

class Player {
private:

	sf::Texture texture;
	sf::RenderWindow *window;

	float x;
	float y;

	float jumpHeight; // altura do pulo
	float gravity;

	float vx;
	float vy;

	sf::SoundBuffer bufferKillEnemy;
	sf::Sound killEnemySound;

	sf::SoundBuffer bufferDownEnemy;
	sf::Sound downEnemySound;

	sf::SoundBuffer bufferJumpSound;
	sf::Sound jumpSound;

public:
	bool alive;

	void update(Plataform ground);
	void walk();
	void jump(Plataform ground);
	bool belowPlataform;

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	float getHeight();
	float getWidth();

	void setPosition(float x, float y);

	bool onGround(Plataform ground); //teste se ele esta em cima do chão
	void testCollisionPlataform(Plataform plataform); //testa se ele esta batendo em alguma plataforma
	void testCollisionEnemy(Enemy& enemy);
	void downEnemy(Plataform &plataform, Enemy& enemy);



	sf::Sprite sprite;
	Player(sf::RenderWindow &janela);
};




#endif /* SOURCE_PLAYER_H_ */
