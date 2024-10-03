#include "Player.h"
#include "Enemy.h"


Player::Player(sf::RenderWindow &janela) { //construtor que define os atributos iniciais do player
	window = &janela;

	texture.loadFromFile("assets/mario.png");
	sprite.setTexture(texture);

	alive = true;

	x = 0;
	y = 0;

	vx = 6;
	vy = 0;

	gravity = 0.65;
	jumpHeight = 14;

	sprite.setPosition(x, y);
	sprite.setOrigin(getWidth() * 0.5, getHeight() * 0.5); //define a origem para o meio do sprite
}

void Player::update(Plataform ground) { // atualiza a posiçao do player
	walk();
	jump(ground);
	testCollisionPlataform(ground);
	sprite.setPosition(x, y);


}

void Player::walk() {

	vx = 6;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) //anda para direita
	|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		x += vx;
		sprite.setScale(1, 1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) //anda para esquerda
	|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		vx = -vx;
		x += vx;

		sprite.setScale(-1, 1); // gira o sprite do playet
	}

	if (x - getWidth() * 0.5 > window->getSize().x) { //faz ele ir de um lado da tela pro outro
		setX(0);
	}
	if (x + getWidth() * 0.5 < 0) {
		setX(window->getSize().x);
	}
}

void Player::jump(Plataform newPlataform) {

	bool pressed = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up));



	if (pressed && onGround(newPlataform)) { //faz ele oular
		vy = -jumpHeight;
		setY(y - 1);
		setPosition(x, y);
	}

	if (!onGround(newPlataform)) { //atualiza a velocidade no ar
		vy += gravity;
	}

	y += vy; //atualiza a posiçao do player
}

bool Player::onGround(Plataform ground) { //testa se ele esta em cima de uma plataforma
	if (sprite.getGlobalBounds().intersects(ground.sprite.getGlobalBounds()) && vy >= 0) {
		vy = 0;
		setY(ground.getY() - getHeight() * 0.5 + 1);

		return true;
	}

	return false;
}

void Player::testCollisionPlataform(Plataform plataform) { //colisao horizontal e vertical com a plataforma
	belowPlataform = false;

	if (sprite.getGlobalBounds().intersects(plataform.sprite.getGlobalBounds()) && vy < 0) {

		if (vx > 0) { //testa a colisao horizontal pela esquerda e colisao vertical
			if (getX() + getWidth() * 0.5 > plataform.getX() + 15) {
				y = plataform.getY() + plataform.getHeight() + getHeight() * 0.5;
				vy = 0;

				belowPlataform = true;
			} else {
				setY(plataform.getY() - getHeight() * 0.5 - 25);
				vy = 0;
			}
		} else { //testa a colisao horizontal pela direita e colisao vertical

			if (plataform.getX() + plataform.getWidht() - 15 > getX() - getWidth() * 0.5) {
				setY(plataform.getY() + plataform.getHeight() + getHeight() * 0.5);
				vy = 0;

				belowPlataform = true;

			} else {
				setY(plataform.getY() - getHeight() * 0.5f - 25);
				vy = 0;
			}
		}
	}
}

void Player::killEnemy(Plataform &plataform, Enemy &enemy) {
	if(belowPlataform && enemy.getX() + 35 > getX() && enemy.getX() - 35 < getX() &&
	enemy.onGround(plataform) && y - enemy.getY() < 100 && enemy.getY() - y < 100){

		enemy.downed = true;
		enemy.sprite.setColor(sf::Color::Red);
	}

}

void Player::testCollisionEnemy(Enemy &enemy) {
	if(sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds())){
		if(enemy.alive && !enemy.downed){
			alive = false;

		}
		if(enemy.downed){
			enemy.alive = false;
		}

	}
}

//funçoes get e set

void Player::setPosition(float x, float y) {
	setX(x);
	setY(y);
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


