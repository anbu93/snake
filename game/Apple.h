#ifndef APPLE_H
#define APPLE_H
#include "..\Object.h"

class Apple : public Object {
public:
	static void create(int number);
	Apple(Point pos, int size);
	void eated();
};

#endif // APPLE_H
