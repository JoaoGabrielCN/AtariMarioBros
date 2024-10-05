#ifndef SOURCE_PLATAFORM_H_
#define SOURCE_PLATAFORM_H_

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<string>

class Plataform {

protected:
	sf::Texture texture;

	float x;
	float y;

public:
	sf::Sprite sprite;

	float getHeight();
	float getWidht();

	float getX();
	float getY();
	Plataform(sf::Texture& texture);
	Plataform();
	void setPosition(float x, float y);
	void setTexture(sf::Texture& texture);
};



#endif /* SOURCE_PLATAFORM_H_ */
