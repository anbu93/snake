#include "Apple.h"
#include "Wall.h"
#include "..\Global.h"
#include "..\Collision.h"
#include <cstdlib>


Point random_point() {
	int x = std::rand()%WIDTH;
	int _x = (x%cell_size);
	x = x - _x + cell_size/2;
	int y = std::rand()%HEIGHT;
	int _y = (y%cell_size);
	y = y - _y + cell_size/2;
	return {x, y};
}

void Apple::create(int number){
	for(int i = 0; i < number; i++){
		Apple* app = new Apple(random_point(), cell_size);
		if (Collision::collise(app)!=app) i--;
	}
}

Apple::Apple(Point pos, int size):Object(pos, size,size, green){
}

void Apple::eated() {
	do {
		position = random_point();
	} while (Collision::collise(this) != this);
}
