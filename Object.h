#ifndef OBJECT_H
#define OBJECT_H

#include "Point.h"
#include "Color.h"

class Object {
public:
	Point position;
	int width;
	int heigth;
	COLOR color;

	Object();
	Object(Point position, int width, int heigth, COLOR color);
	virtual ~Object();
	void draw();
};

#endif
