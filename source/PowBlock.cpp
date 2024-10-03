/*
 * PowBlock.cpp
 *
 *  Created on: 3 de out. de 2024
 *      Author: Aldo
 */

#include "PowBlock.h"

PowBlock::PowBlock() {
	lifes = 9;
}

void PowBlock::update() {
	if(lifes <= 0){
		setPosition(1000, 1000);
	}
}
