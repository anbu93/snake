#ifndef WALL_H
#define WALL_H
#include "..\Object.h"

class Wall : public Object {
public:
	Wall(Point pos, int w, int h)
	:Object(pos, w, h, blue){}
};

#endif // WALL_H