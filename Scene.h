#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
	virtual void run() = 0;
	Scene();
	virtual ~Scene();
};

#endif
