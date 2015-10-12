#ifndef SNAK_HEAD_H
#define SNAK_HEAD_H
#include "..\Object.h"
#include "..\Direct.h"

class SnakeHead : public Object {
private:
	Direct direct;
	bool pause_flag;
public:
	SnakeHead(Point position);
	virtual ~SnakeHead();

	void move();
	void redirect(Direct direct);
	bool paused();
};

#endif // SNAKE_HEAD_H
