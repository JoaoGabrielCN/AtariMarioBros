/*
 * Enemy.cpp
 *
 *  Created on: 29 de ago. de 2024
 *      Author: Aldo
 */

#include "Enemy.h"

int Enemy::getDirection() {
	return this->direction;
}

Enemy::Enemy(sf::RenderWindow &janela , int direction) {

	alive = true;
	downed = false;


	window = &janela;

	x = 0;
	y = 0;
	vx = 1;
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



	if(!alive){
		x = 10000;

	}

	if(downed){
		vx = 0;
		return;
		sprite.setColor(sf::Color::Red);
	}

	if (direction == 1) {

		sprite.setScale(-1, 1);
	} else {

		vx = -1;

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

void Enemy::setDirection(int num){
	direction = num;
}

void Enemy::setSprite(std::string path) {
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

void Enemy::testEnemyCollsion(Enemy &other) {
    if (this != &other && sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds()) && !downed && !other.downed) {

    		direction = -direction;
            vx = -vx;
            other.setDirection(-other.getDirection());
            other.setVx(-other.getVx());

        }
    }


void Enemy::setVx(float vx){
	this->vx = vx;
}

float Enemy::getVx(){
	return vx;
}

void Enemy::getUp() {
    if (downed && alive) {
        if (!clockStarted) {

            clock.restart();
            clockStarted = true;
        }

        if (clock.getElapsedTime().asSeconds() > 6) {
            downed = false;
            clockStarted = false;
            vx = 1 *  direction;
            sprite.setColor(sf::Color::White);
        }
    } else {
        clock.restart();
        clockStarted = false;
    }
}
