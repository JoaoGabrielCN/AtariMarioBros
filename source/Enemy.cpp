#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &janela, int direction, sf::Texture &texture) {

	this->texture = texture;

	alive = true;
	downed = false;

	window = &janela;

	x = 0;
	y = 0;
	vx = 1.1;
	vy = 0;

	this->direction = direction;
	alive = true;
	gravity = 4;

	frameSize = sf::Vector2i(190 / 4, 49);
	atualFrame = 0;
	animationClock.restart();

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));


	sprite.setOrigin(frameSize.x * 0.5, frameSize.y * 0.5);

	setPosition(x, y);
}

void Enemy::updateAnimation() {
	if (downed) {
		return;
	}

	if (animationClock.getElapsedTime().asSeconds() > 0.3f) {
		atualFrame = (atualFrame + 1) % 3;
		sprite.setTextureRect(sf::IntRect(atualFrame * frameSize.x, 0, frameSize.x,frameSize.y));
		sprite.setOrigin(frameSize.x * 0.5, frameSize.y * 0.5);
		animationClock.restart();
	}
}

void Enemy::update(Plataform ground) {
	walk();
	onGround(ground);
	setPosition(x, y);

	if(onGround(ground)) updateAnimation();
}

void Enemy::walk() {
	if (!alive) {
		x = 10000;
	}

	if (downed) {
		vx = 0;
		sprite.setTextureRect(sf::IntRect(150, 0, 50, frameSize.y));
		return;
	}

	if (direction == 1) {
		vx = 1.1;
		sprite.setScale(1, 1);
	} else {
		vx = -1.1;
		sprite.setScale(-1, 1);
	}

	x += vx;
	testWindowColission();
}

bool Enemy::onGround(Plataform ground) {
	if (sprite.getGlobalBounds().intersects(ground.sprite.getGlobalBounds())) {
		vy = 0;
		setY(ground.getY() - getHeight() * 0.5 + 1);
		return true;
	} else {
		vy = gravity;
	}

	y += vy;
	return false;
}

void Enemy::testEnemyCollsion(Enemy &other) {

	if (this != &other && sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds()) && !this->downed) {

		if (vy > other.vy) {
			if (other.x < x) {
				x = x + 10;
			} else {
				x = x - 10;
			}
		}
		direction = -direction;
		vx = -vx;
		other.setDirection(-other.getDirection());
		other.setVx(-other.getVx());
	}

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
			vx = 1 * direction;
			sprite.setColor(sf::Color::White);
		}
	} else {
		clock.restart();
		clockStarted = false;
	}
}

void Enemy::testWindowColission() {
	if (x - getWidth() * 0.5 > window->getSize().x) {
		setX(0);
	}
	if (x + getWidth() * 0.5 < 0) {
		setX(window->getSize().x);
	}
}

void Enemy::toggleDirection() {
	direction = -direction;
}

void Enemy::setVx(float vx) {
	this->vx = vx;
}

float Enemy::getVx() {
	return vx;
}

void Enemy::setPosition(float x, float y) {
	this->x = x;
	this->y = y;

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
	return frameSize.y;
}

float Enemy::getWidth() {
	return frameSize.x;
}
void Enemy::setDirection(int num) {
	direction = num;
}

void Enemy::setSprite(std::string path) {
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

int Enemy::getDirection() {
	return this->direction;
}

