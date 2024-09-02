/*
 * Enemy.cpp
 *
 *  Created on: 29 de ago. de 2024
 *      Author: Aldo
 */

#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &janela , int direction) {


	window = &janela;

	x = 0;
	y = 0;
	vx = 1.5;
	vy = 0;

	this->direction = direction;

	alive = true;
	gravity = 4;

	texture.loadFromFile("assets/koopa.png");
	sprite.setTexture(texture);
	sprite.setOrigin(getWidth() * 0.5, getHeight() * 0.5);
	setPosition(x, y);
}

void Enemy::update(Plataform ground) {

	walk();
	onGround(ground);
	setPosition(x, y);
}

void Enemy::walk() {

	if (direction == 1) {

		sprite.setScale(-1, 1);
	} else {

		vx = -1.5;

		sprite.setScale(1, 1);
	}

	x += vx;

	if (x - getWidth() * 0.5 > window->getSize().x) { //faz ele ir de um lado da tela pro outro
		setX(0);
	}
	if (x + getWidth() * 0.5 < 0) {
		setX(window->getSize().x);
	}
}

bool Enemy::onGround(Plataform ground) {
	if (sprite.getGlobalBounds().intersects(ground.sprite.getGlobalBounds())) {
		vy = 0;
		setY(ground.getY() - getHeight() * 0.5 + 1);

		return true;
	}else{
		vy = gravity;
	}

	y += vy;

	return false;

}

void Enemy::setPosition(float x, float y) {
	setX(x);
	setY(y);
	sprite.setPosition(x, y);
}

float Enemy::getX() {
	return x;
}

float Enemy::getY() {
	return y;
}

void Enemy::setX(float x) {
	this->x = x;
}

void Enemy::setY(float y) {
	this->y = y;
}

float Enemy::getHeight() {
	return sprite.getGlobalBounds().height;
}

float Enemy::getWidth() {
	return sprite.getGlobalBounds().width;
}

void Enemy::setSprite(std::string path) {
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}


