#ifndef SOURCE_PIPE_H_
#define SOURCE_PIPE_H_

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enemy.h"

class Pipe {
private:
	float x;
	float y;
	int scale;

	sf::Texture texture;

	sf::SoundBuffer bufferPipeTravel;
	sf::Sound pipeTravelSound;

public:
	sf::Sprite sprite;

	Pipe();
	Pipe(float x, float y, int scale, sf::Texture& texture);
	Pipe(sf::Texture& texture);

	void setX(float x);
	int getX();

	void setY(float y);
	int getY();

	void setPosition(float x, float y);

	float getWidth();
	float getHeight();

	void setScale(int scale);

	void pipeTravel(Enemy& enemy, Pipe& other);

	void setSoundBuffer(sf::SoundBuffer& soundBuffer);
};

#endif /* SOURCE_PIPE_H_ */
