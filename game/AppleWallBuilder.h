#ifndef APPLE_WALL_BUILDER_H
#define APPLE_WALL_BUILDER_H
#include "..\Point.h"

class AppleWallBuilder {
private:
	AppleWallBuilder* unique_instance;
public:
	static void create(const char* level_name);
	static void eated_apple(Apple* apple);
private:
	AppleWallBuilder();
	static void check_instance();

	Point random_point();
	void _create(const char* leel_name);
	void _create_object(char mask, Point pos);
};

#endif // APPLE_WALL_BUILDER_H
