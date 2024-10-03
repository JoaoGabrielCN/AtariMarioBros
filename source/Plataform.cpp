#include "Plataform.h"

Plataform::Plataform(sf::Texture& texture) {
	this->texture = texture;

	sprite.setTexture(texture);

	x = 0;
	y = 0;

}

Plataform::Plataform(){
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


void Plataform::setTexture(sf::Texture& texture) { //define o sprite
	this->texture = texture;

	sprite.setTexture(texture);
}

float Plataform::getX() { // pega o x
	return x;
}

float Plataform::getY() { // pega o y
	return y;
}
