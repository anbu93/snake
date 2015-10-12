#ifndef OPEN_GL_H

#define OPEN_GL_H

namespace OpenGL {

	int LoadTexture(char *FileName) ;

	void display();

	void timer(int = 0);

	// фнкции ввода
	void Keyboard(unsigned char Key, int MouseX, int MouseY);
	void SpecialKeyboard(int Key, int MouseX, int MouseY);
	void Mouse(int Button, int State, int MouseX, int MouseY);
	void Motion(int MouseX, int MouseY);

};

#endif
