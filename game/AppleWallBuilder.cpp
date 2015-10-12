#include "AppleWallBuilder.h"
#include "Apple.h"
#include "Wall.h"


/// field
AppleWallBuilder* AppleWallBuilder::unique_instance = 0;

/// public method
void AppleWallBuilder::create(const char* level_name){

}

/// private methods
AppleWallBuilder::AppleWallBuilder() {}

void AppleWallBuilder::check_instance() {
	if (!unique_instance) 
		unique_instance = new AppleWallBuilder();
}