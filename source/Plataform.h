
/*
 * Plataform.h
 *
 *  Created on: 21 de ago. de 2024
 *      Author: Aldo
 */

#ifndef SOURCE_PLATAFORM_H_
#define SOURCE_PLATAFORM_H_

#include<SFML/Graphics.hpp>
#include<string>

class Plataform {

private:
	sf::Texture texture;

	float x;
	float y;

public:
	sf::Sprite sprite;

	float getHeight();
	float getWidht();

	float getX();
	float getY();
	Plataform();
	void setPosition(float x, float y);
	void setSprite(std::string path);
};

#endif /* SOURCE_PLATAFORM_H_ */
