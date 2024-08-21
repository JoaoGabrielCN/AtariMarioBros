/*
 * Game.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef GAME_H_
#define GAME_H_

#include<SFML/Graphics.hpp>
#include "Player.h"

class Game {
private:
	void eventsLoop();
	void update();
	void draw();
	sf::RenderWindow window;
	sf::CircleShape shape;
	Player player;
public:
	Game();
	void run();
};

#endif /* GAME_H_ */
