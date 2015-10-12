#include "Collision.h"
#include <cmath>

Object* Collision::collise(Object* object){
	for(int i = 0; i < List::size(); i++)
		if (collise(List::get(i), object)&&List::get(i)!=object)
          return List::get(i);
	return object;
}

bool Collision::collise(Object* a, Object* b){
	bool check_x = std::abs(a->position.x - b->position.x)<
							(a->width/2 + b->width/2);
	bool check_y = std::abs(a->position.y - b->position.y)<
							(a->heigth/2 + b->heigth/2);
	return check_x && check_y;
}
