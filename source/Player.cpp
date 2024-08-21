/*
 * Player.cpp
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#include "Player.h"

Player::Player(sf::RenderWindow &janela) {

	window = &janela;
    texture.loadFromFile("assets/mario.png");
    sprite.setTexture(texture);

    x = window->getSize().x * 0.5;
    y = window->getSize().y - sprite.getGlobalBounds().height * 0.5;
    vx = 0.2;
    vy = 0.2;

    sprite.setPosition(x, y);
    sprite.setOrigin(sprite.getGlobalBounds().width * 0.5, sprite.getGlobalBounds().height * 0.5);

}

void Player::update() {
	walk();
	sprite.setPosition(x, y);
}

void Player::walk() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		x = x + vx;
		sprite.setScale(1, 1);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		x = x - vx;
		sprite.setScale(-1, 1);
	}
}
