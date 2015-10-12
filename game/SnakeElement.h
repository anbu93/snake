#ifndef SNAKE_ELEMENT_H
#define SNAKE_ELEMENT_H_H

#include "..\Object.h"


class SnakeElement : public Object {
public:
	SnakeElement(Point position, int width, int heigth, COLOR color);
	virtual ~SnakeElement();
	void set_position(Point position);
};

#endif