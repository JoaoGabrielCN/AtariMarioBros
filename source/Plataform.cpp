/*
 * Plataform.cpp
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#include "Plataform.h"

Plataform::Plataform() {
	x = 0;
	y = 0;
}

float Plataform::getHeight() {
	return sprite.getGlobalBounds().height;
}

float Plataform::getWidht() {
	return sprite.getGlobalBounds().width;
}

void Plataform::setPosition(float x, float y) {
	this->x = x;
	this->y = y;

	sprite.setPosition(x, y);
}

void Plataform::setSprite(std::string path) {
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

float Plataform::getX() {
	return x;
}

float Plataform::getY() {
	return y;
}
