/*
 * Enemy.h
 *
 *  Created on: 29 de ago. de 2024
 *      Author: Aldo
 */

#include<SFML/Graphics.hpp>
#include"Plataform.h"
#include"Player.h"
#include <string>

using namespace std;


#ifndef SOURCE_ENEMY_H_
#define SOURCE_ENEMY_H_

class Enemy {
private:

	sf::RenderWindow *window;

	float x;
	float y;

	float gravity;

	float vx;
	float vy;

	int direction;

public:
	bool alive;

	void update(Plataform ground);
	void walk();
	void jump(Plataform ground);

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	float getHeight();
	float getWidth();

	void setPosition(float x, float y);

	bool onGround(Plataform ground);
	void setSprite(string path);
	sf::Texture texture;
	sf::Sprite sprite;
	Enemy(sf::RenderWindow &janela, int direction);
};

#endif /* SOURCE_ENEMY_H_ */
