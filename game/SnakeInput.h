#ifndef SNAKE_INPUT_H
#define SNAKE_INPUT_H

#include "..\Input.h"
#include "Snake.h"


class SnakeInput : public Input {
private:
	Snake* snake;
public:
	SnakeInput(Snake* snake);
	virtual void _press_key(unsigned char key);
};

#endif