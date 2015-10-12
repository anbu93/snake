#ifndef LEVEL_H

#define LEVEL_H
#include "..\Scene.h"
#include "Snake.h"

class Level : public Scene {
private:
	Snake* snake;
public:
	Level();
	virtual void run();
	virtual ~Level();
};

#endif
