#include "Apple.h"
#include "AppleWallBuilder.h"

Apple::Apple(Point pos, int size):Object(pos, size,size, green){
}

void eated() {
	AppleWallBuilder::eated_apple(this);
}