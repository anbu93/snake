#include "Apple.h"
#include "AppleWallBuilder.h"

Apple::Apple(Point pos, int size):Object(pos, size,size, green){
}

void Apple::eated() {
	AppleWallBuilder::eated_apple(this);
}
