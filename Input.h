#ifndef INPUT_H

#define INPUT_H

class Input {
private:
	static Input* unique_instance;
public:
	static void press_key(unsigned char key);
	static void press_mouse(int key, int stat, int x, int y);
	static void mouse_position(int x, int y);
	static void set(Input* input);
protected:
	virtual void _press_key(unsigned char key);
	virtual void _press_mouse(int key, int stat, int x, int y);
	virtual void _mouse_position(int x, int y);
protected:
	static void check_instance();
	Input();
	virtual ~Input();
};

#endif
