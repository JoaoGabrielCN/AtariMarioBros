/*
 * Player.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<SFML/Graphics.hpp>
#include"Plataform.h"

class Player {
private:

	sf::Texture texture;
	sf::RenderWindow *window;

	float x;
	float y;

public:
	float vx;
	float vy;
	void update();
	void walk();

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	float getHeight();
	float getWidth();

	void setPosition(float x, float y);

	sf::Sprite sprite;
	Player(sf::RenderWindow &janela);
};

#endif /* PLAYER_H_ */
