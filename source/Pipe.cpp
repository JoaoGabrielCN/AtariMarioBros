#include "Pipe.h"

Pipe::Pipe() {
	x = 0;
	y = 0;
	scale = 1;

	sprite.setPosition(x, y);


}

Pipe::Pipe(float x, float y, int scale, sf::Texture& texture) {
	this->x = x;
	this->y = y;
	this->texture = texture;
	this->scale = scale;

	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setScale(scale, 1);



}

Pipe::Pipe(sf::Texture& texture) {
	x = 0;
	y = 0;
	scale = 1;
	this->texture = texture;

	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setScale(scale, 1);



}

void Pipe::setScale(int scale){
	this->scale = scale;

	sprite.setScale(scale, 1);
}

void Pipe::setX(float x) {
	this->x = x;
}

int Pipe::getX() {
	return x;
}

void Pipe::setY(float y) {
	this->y = y;
}

int Pipe::getY() {
	return y;
}

void Pipe::setPosition(float x, float y) {
	this->x = x;
	this->y = y;

	sprite.setPosition(x, y);
}

float Pipe::getWidth() {
	return sprite.getGlobalBounds().width;
}

float Pipe::getHeight() {
	return sprite.getGlobalBounds().height;
}

void Pipe::pipeTravel(Enemy &enemy, Pipe& other){
	if(this->sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds())){
		if(scale == 1){
			enemy.setPosition(other.getX() + other.getWidth(), other.getY() + other.getHeight() - enemy.getHeight()* 0.5);
			enemy.toggleDirection();
		}else if(scale == -1){
			enemy.setPosition(other.getX() - other.getWidth(), other.getY() + other.getHeight() - enemy.getHeight()* 0.5);
			enemy.toggleDirection();
		}

		//pipeTravelSound.play();
	}


}


