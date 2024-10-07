#ifndef SOURCE_ENEMY_H_
#define SOURCE_ENEMY_H_

#include<SFML/Graphics.hpp>
#include"Plataform.h"
#include"Player.h"
#include <string>
#include<iostream>
#include <SFML/Audio.hpp>

using namespace std;

class Enemy {
private:

	sf::RenderWindow *window;

	float x;
	float y;

	float gravity;

	float vx;
	float vy;

	sf::Vector2i frameSize;
	int atualFrame;

	sf::Clock animationClock;


public:
	bool alive;
	int direction;
	bool downed;
	bool clockStarted;
	sf::Clock clock;

	sf::Texture texture;
	sf::Sprite sprite;


	Enemy(sf::RenderWindow &janela, int direction, sf::Texture& texture);
	void update(Plataform ground);
	void walk();

	void setPosition(float x, float y);
	void setDirection(int num);
	int getDirection();

	void testEnemyCollsion(Enemy &other);

	bool onGround(Plataform ground);
	void setSprite(string path);

	void setVx(float vx);
	float getVx();

	void getUp();
	void toggleDirection();

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	float getHeight();
	float getWidth();

	void testWindowColission();

	void updateAnimation();

};

#endif /* SOURCE_ENEMY_H_ */
