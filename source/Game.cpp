/*
 * Game.cpp
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#include "Game.h"

Game::Game():window(sf::VideoMode(640, 480), "SFML works!"), player(window){
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);


}

void Game::eventsLoop() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update() {
	player.update();
}

void Game::draw() {
	window.clear();
	window.draw(player.sprite);
	window.display();
}

void Game::run(){
	while(window.isOpen()){
	eventsLoop();
	update();
	draw();
	}
}
