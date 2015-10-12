#ifndef COLLISION_H
#define COLLISION_H

#include "List.h"

class Collision {
public:
	static Object* collise(Object* object);
	static bool collise(Object* first, Object* second);
};

#endif // COLLISION_H
