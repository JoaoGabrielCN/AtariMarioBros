
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

float Plataform::getHeight() { // pega a altura da plataforma
	return sprite.getGlobalBounds().height;
}

float Plataform::getWidht() { // pega a largura da plataforma
	return sprite.getGlobalBounds().width;
}

void Plataform::setPosition(float x, float y) { // define a posçao
	this->x = x;
	this->y = y;

	sprite.setPosition(x, y);
}


void Plataform::setSprite(std::string path) { //define o sprite
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

float Plataform::getX() { // pega o x
	return x;
}

float Plataform::getY() { // pega o y
	return y;
}
