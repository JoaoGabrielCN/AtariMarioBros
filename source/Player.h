
/*
 * Player.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef SOURCE_PLAYER_H_
#define SOURCE_PLAYER_H_

#include<SFML/Graphics.hpp>
#include"Plataform.h"

class Player {
private:

	sf::Texture texture;
	sf::RenderWindow *window;

	float x;
	float y;

	float jumpHeight;
	float gravity;

public:
	float vx;
	float vy;
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
	void testCollision(Plataform plt);



	sf::Sprite sprite;
	Player(sf::RenderWindow &janela);
};

#endif /* SOURCE_PLAYER_H_ */
