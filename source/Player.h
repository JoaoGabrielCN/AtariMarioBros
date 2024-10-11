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

	sf::Vector2i frameSize;
	int atualFrame;
	sf::Clock animationClock;

public:
	bool alive;
	bool belowPlataform;
	sf::Sprite sprite;

	void update(Plataform ground);
	void walk();
	void jump(Plataform ground);


	float getX();
	float getY();
	void updateAnimation();

	void setX(float x);
	void setY(float y);

	float getHeight();
	float getWidth();

	void setPosition(float x, float y);

	bool onGround(Plataform ground); //teste se ele esta em cima do chão
	void testCollisionPlataform(Plataform plataform); //testa se ele esta batendo em alguma plataforma
	void testCollisionEnemy(Enemy &enemy);
	void testWindowCollision();
	void downEnemy(Plataform &plataform, Enemy &enemy);


	Player(sf::RenderWindow &janela);

};

#endif /* SOURCE_PLAYER_H_ */
