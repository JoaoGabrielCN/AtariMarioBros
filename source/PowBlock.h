/*
 * PowBlock.h
 *
 *  Created on: 3 de out. de 2024
 *      Author: Aldo
 */

#ifndef SOURCE_POWBLOCK_H_
#define SOURCE_POWBLOCK_H_
#include "Plataform.h"

class PowBlock : public Plataform{
public:
	PowBlock();

	int lifes;
	void update();
};

#endif /* SOURCE_POWBLOCK_H_ */
