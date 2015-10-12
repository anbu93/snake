#include <cstdlib>
#include <fstream>
#include <iostream>

#include "AppleWallBuilder.h"
#include "Apple.h"
#include "Wall.h"
#include "..\Collision.h"
#include "..\Global.h"

/// ********** field **********
AppleWallBuilder* AppleWallBuilder::unique_instance = 0;



/// ********** public method **********
void AppleWallBuilder::create(const char* level_name){
	check_instance();
	unique_instance->_create(level_name);
}

void AppleWallBuilder::eated_apple(Apple* apple){
	check_instance();
	do {
		apple->position = unique_instance->random_point();
	} while (Collision::collise(apple) != apple);
}



/// ********** private methods **********
AppleWallBuilder::AppleWallBuilder() {}

void AppleWallBuilder::check_instance() {
	if (!unique_instance)
		unique_instance = new AppleWallBuilder();
}

Point AppleWallBuilder::random_point() {
	int x = std::rand()%WIDTH;
	int _x = (x%cell_size);
	x = x - _x + cell_size/2;
	int y = std::rand()%HEIGHT;
	int _y = (y%cell_size);
	y = y - _y + cell_size/2;
	return Point(x, y);
}

void AppleWallBuilder::_create(const char* level_name){
	std::ifstream level(level_name);
	if (level.is_open() == false) {
		std::cout << "Not find level map " << level_name;
		std::cout << " create sample level." << std::endl;
		return create("levels\\sample.txt");
	}
	char mask;
	for(int i = 0; i < HEIGHT; i+= cell_size){
		for(int j = 0; j < WIDTH; j+= cell_size){
			if (level.eof()) {
				std::cout << "unexpectet end of file " << level_name << std::endl;
				return;
			}
			level >> mask;
			if (mask != '.') _create_object(mask, Point(j, (HEIGHT-i) - (HEIGHT-i)%cell_size));
		}
	}
}

void AppleWallBuilder::_create_object(char mask, Point pos){
	Object* object;
	switch (mask) {
			case '#': // wall
				object = new Wall(pos, cell_size, cell_size);
				break;
			case '@': // apple
				object = new Apple(pos, cell_size);
				break;
			case 'S': // snake
				// TODO настроить точку появления змейки
			default: // error. not this mask!
				std::cout << "not a mask " << mask;
				std::cout << " on line" << pos.y << " char of " << pos.x << std::endl;
				break;
			}
}
