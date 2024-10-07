#ifndef SOURCE_POWBLOCK_H_
#define SOURCE_POWBLOCK_H_
#include "Plataform.h"

class PowBlock : public Plataform{
public:
	PowBlock();

	int lifes;
	void update();
	void reset();
};

#endif /* SOURCE_POWBLOCK_H_ */
