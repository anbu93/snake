#include "Level.h"
#include "..\List.h"

#include "..\List.h"

Level::Level() {
	snake = new Snake();
	// Apples and walls create
}

void Level::run() {
	snake->run();
}

Level::~Level() {
	delete snake;
	snake = 0;
	List::clean();
}
