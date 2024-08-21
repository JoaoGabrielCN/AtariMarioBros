/*
 * Player.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<SFML/Graphics.hpp>

class Player {
private:

	sf::Texture texture;
	sf::RenderWindow *window;
	float x;
	float y;
	float vx;
	float vy;

public:
	void update();
	void walk();
	sf::Sprite sprite;
	Player(sf::RenderWindow &wjanela);
};

#endif /* PLAYER_H_ */
