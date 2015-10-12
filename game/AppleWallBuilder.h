#ifndef APPLE_WALL_BUILDER_H
#define APPLE_WALL_BUILDER_H

class AppleWallBuilder {
private:
	AppleWallBuilder* unique_instance;
public:
	static void create(const char* level_name);
private:
	AppleWallBuilder();
	static void check_instance();
};

#endif // APPLE_WALL_BUILDER_H
