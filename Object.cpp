#include <GL\glut.h>
#include "Object.h"
#include "List.h"

inline static void set_color(COLOR color);


// ********** public methods **********

Object::Object()
: position(Point(0, 0)), width(0), heigth(0), color(black){
    List::add(this);
}

Object::Object(Point position, int width, int heigth, COLOR color)
: position(position), width(width), heigth(heigth), color(color){
    List::add(this);
}

Object::~Object() {
    List::remove(this);
}

void Object::draw() {
	set_color(color);
	glRectf(position.x - width/2, position.y - heigth/2,
			position.x + width/2, position.y + heigth/2);
}



// ********** Other functions **********

inline static void set_color(COLOR color){
	switch(color) {
		case red: glColor3f(1.0, 0.0, 0.0); break;
		case green: glColor3f(0.0, 1.0, 0.0); break;
		case blue: glColor3f(0.0, 0.0, 1.0); break;
		case black: glColor3f(0.0, 0.0, 0.0); break;
		case white: glColor3f(1.0, 1.0, 1.0); break;
		case black_red: glColor3f(0.5, 0.0, 0.0); break;
		default: glColor3f(0.0, 0.0, 0.0); break;
	}
}
