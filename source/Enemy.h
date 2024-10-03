#ifndef SOURCE_ENEMY_H_
#define SOURCE_ENEMY_H_

#include<SFML/Graphics.hpp>
#include"Plataform.h"
#include"Player.h"
#include <string>

using namespace std;

class Enemy {
private:

	sf::RenderWindow *window;

	float x;
	float y;

	float gravity;

	float vx;
	float vy;

public:
	bool alive;
	int direction;
	bool downed;
	bool clockStarted;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;

	Enemy(sf::RenderWindow &janela, int direction, sf::Texture& texture);
	void update(Plataform ground);
	void walk();

	void setPosition(float x, float y);
	void setDirection(int num);
	int getDirection();

	void testEnemyCollsion(Enemy &other);

	bool onGround(Plataform ground);
	void setSprite(string path);

	void setVx(float vx);
	float getVx();

	void getUp();
	void toggleDirection();

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	float getHeight();
	float getWidth();

	void testWindowColission();
};

#endif /* SOURCE_ENEMY_H_ */
