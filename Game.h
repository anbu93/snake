#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game {
private:
	static Game* unique_instance;
	Scene* scene;
public:
	static void set_scene(Scene* _scene);
	static void run();
private:
	Game();
	static void check_instance();	
};

#endif