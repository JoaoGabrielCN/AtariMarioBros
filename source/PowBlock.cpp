#include "PowBlock.h"

PowBlock::PowBlock() {
	lifes = 9;
}

void PowBlock::update() {
	if(lifes <= 0){
		setPosition(1000, 1000);
	}
}

void PowBlock::reset(){
	lifes = 9;
}
