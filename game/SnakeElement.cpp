#include "SnakeElement.h"


/// *********** public methods ***************

SnakeElement::SnakeElement(Point position, int width, int heigth, COLOR color)
: Object(position, width, heigth, color) {}

SnakeElement::~SnakeElement() {}

void SnakeElement::set_position(Point position) {
	this->position = position;
}
