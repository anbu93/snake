#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeElement.h"
#include <queue>
#include "..\Direct.h"
#include "SnakeHead.h"

class Snake {
private:
	std::queue<SnakeElement*> elements;
	SnakeHead* head;
	bool repeat_flag;
public:
	Snake();
	void run();
	void redirect(Direct direct);
private:
	SnakeElement* get_last_element();
	Object* get_collised();
	void win();
	void lose();
	void play_again();
	SnakeElement* build_element();
};

#endif // SNAKE_H
