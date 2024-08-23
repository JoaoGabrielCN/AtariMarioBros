#include "Player.h"
#include <iostream>

Player::Player(sf::RenderWindow &janela) {
	window = &janela;

	texture.loadFromFile("assets/mario.png");
	sprite.setTexture(texture);

	x = 0;
	y = 0;

	vx = 6.f;
	vy = 0;

	sprite.setPosition(x, y);
	sprite.setOrigin(getWidth() * 0.5f, getHeight() * 0.5f);
}

void Player::update() {
	walk();
	sprite.setPosition(x, y);

}

void Player::walk() {
	vx = 6.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		x += vx;
		sprite.setScale(1, 1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		vx = -vx;
		x += vx;

		sprite.setScale(-1, 1);
	}

	if (x - getWidth() * 0.5 > window->getSize().x) {
		x = 0;
	}
	if (x + getWidth() * 0.5 < 0) {
		x = window->getSize().x;
	}
}

void Player::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	sprite.setPosition(x, y);
}

float Player::getX() {
	return x;
}

float Player::getY() {
	return y;
}

void Player::setX(float x) {
	this->x = x;
}

void Player::setY(float y) {
	this->y = y;
}

float Player::getHeight() {
	return sprite.getGlobalBounds().height;
}

float Player::getWidth() {
	return sprite.getGlobalBounds().width;
}

