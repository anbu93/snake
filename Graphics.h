#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics {
private:
	static Graphics* unique_instance;
public:
	static void run();
private:
	Graphics();
	static void check_instance();
};

#endif
