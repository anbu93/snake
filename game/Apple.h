#ifndef APPLE_H
#define APPLE_H
#include "..\Object.h"

class Apple : public Object {
public:
	Apple(Point pos, int size);
	void eated();
};

#endif // APPLE_H
