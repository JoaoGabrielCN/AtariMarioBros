/*
 * Game.cpp
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML works!"), player(window) {
	initializeVar();
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
	window.draw(floor.sprite);
	window.draw(player.sprite);
	for (unsigned int i = 0; i < plataforms.size(); ++i) {
		plataforms[i].setSprite("assets/plataform.png");
		window.draw(plataforms[i].sprite);
	}
	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		eventsLoop();
		update();
		draw();
	}
}

void Game::initializeVar() {
	window.setVerticalSyncEnabled(true);
	floor.setSprite("assets/floor.png");
	floor.setPosition(0, window.getSize().y - floor.getHeight());

	player.setPosition(window.getSize().x * 0.5, window.getSize().y - floor.getHeight() - (player.getHeight() * 0.5));
	setPlataforms();
}

void Game::setPlataforms() {
	Plataform newPlaform;
	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(-111, 435);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 111, 435);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x * 0.5 - newPlaform.getWidht() * 0.5, 270);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(-259, 300);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 259, 300);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(-74, 110);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 74, 110);
	plataforms.push_back(newPlaform);

}
