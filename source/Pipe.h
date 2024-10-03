/*
 * Pipe.h
 *
 *  Created on: 2 de out. de 2024
 *      Author: Aldo
 */

#ifndef SOURCE_PIPE_H_
#define SOURCE_PIPE_H_

#include<SFML/Graphics.hpp>
#include"Enemy.h"

class Pipe {
private:
	float x;
	float y;
	int scale;

	sf::Texture texture;

public:
	sf::Sprite sprite;

	Pipe();
	Pipe(float x, float y, int scale, sf::Texture& texture);
	Pipe(sf::Texture& texture);

	void setX(float x);
	int getX();

	void setY(float y);
	int getY();

	void setPosition(float x, float y);

	float getWidth();
	float getHeight();

	void setScale(int scale);

	void testEnemyCollision(Enemy& enemy, Pipe& other);
};

#endif /* SOURCE_PIPE_H_ */
