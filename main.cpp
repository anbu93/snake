#include <iostream>
#include <GL\glut.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "OpenGL.h"
#include "Global.h"
#include "Game.h"
#include "game\Level.h"

int main(int argc, char**argv)
{
	srand(time(0));
	glutInit(&argc, argv);
	glEnable(GL_TEXTURE_2D);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(300, 143);
	glutCreateWindow("Game");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH, 0, HEIGHT, 1, 0);
	glutDisplayFunc(OpenGL::display);
	glutTimerFunc(MAIN_TIMEOUT, OpenGL::timer, 0);
	glutKeyboardFunc(OpenGL::Keyboard);
	glutSpecialFunc(OpenGL::SpecialKeyboard);
	glutMouseFunc(OpenGL::Mouse);
	glutMotionFunc(OpenGL::Motion);
	glutPassiveMotionFunc(OpenGL::Motion);

	// TODO unit tests
	Game::set_scene(new Level());
	if (OpenGL::LoadTexture("Laki.bmp")!=1) {
		cout << "Not loaded image!\n";
	}

	glutMainLoop();
}
