#include "SnakeHead.h"
#include "..\Global.h"

SnakeHead::SnakeHead(Point position)
: Object(position, cell_size, cell_size, black_red),
direct(none), pause_flag(true) {
}

void SnakeHead::redirect(Direct _direct){
	if (_direct == none) pause_flag = true;
	else if (_direct%2 != direct%2 || direct == none || _direct == direct){
		direct = _direct;
		pause_flag = false;
	}
}

void SnakeHead::move() {
	switch(direct) {
		case up: position.y += cell_size; break;
		case down: position.y -= cell_size; break;
		case left: position.x -= cell_size; break;
		case right: position.x += cell_size; break;
		default: break;
	}
}

SnakeHead::~SnakeHead() {}

bool SnakeHead::paused() {
	return pause_flag;
}
