#include <GL/glut.h>
#include <cstdlib>
#include <stdio.h>
#include <malloc.h>

#include "OpenGL.h"
#include "Global.h"
#include "Graphics.h"
#include "Input.h"
#include "Game.h"

namespace OpenGL{

    GLuint  textura_id;

    struct textura_struct {
        int W;
        int H;
        unsigned char *Image;
    }get_textura;

}
int OpenGL::LoadTexture(char *FileName)
{
	FILE *F;
	/* Открываем файл */
	if ((F = fopen(FileName, "rb")) == NULL)
		return 0;
	/*Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну */
	fseek(F, 18, SEEK_SET);
	fread(&(get_textura.W), 2, 1, F);
	fseek(F, 2, SEEK_CUR);
	fread(&(get_textura.H), 2, 1, F);
	printf("%d x %d\n", get_textura.W, get_textura.H);

	/* Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой */
	if ((get_textura.Image = (unsigned char *) malloc(sizeof(unsigned char)*4*get_textura.W * get_textura.H)) == NULL) {
		fclose(F);
		return 0;
	}
	/* Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя */
	fseek(F, 30, SEEK_CUR);
	fread(get_textura.Image, 4, get_textura.W * get_textura.H, F);

	glGenTextures(1, &textura_id);
	glBindTexture(GL_TEXTURE_2D, textura_id);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, get_textura.W, get_textura.H, GL_RGB, GL_UNSIGNED_BYTE, get_textura.Image);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, get_textura.W, get_textura.H, GL_RGBA, GL_UNSIGNED_BYTE, get_textura.Image);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, get_textura.W, get_textura.H, 0, GL_RGB, GL_UNSIGNED_BYTE,  get_textura.Image);
	free(get_textura.Image);
	fclose(F);

	return 1;
}



void OpenGL::display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_LINES); // рисовка фона(клетка)
	for (int i = 0; i < WIDTH; i += cell_size){
		glVertex2f(i, 0); glVertex2f(i, HEIGHT);
	}
	for (int j = 0; j< HEIGHT; j += cell_size){
		glVertex2f(0, j); glVertex2f(WIDTH, j);
	}
    glEnd();

	/*glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textura_id);
            glBegin(GL_QUADS);
                glTexCoord2d(0,0); glVertex2f(0, 0 ); //left bottom
                glTexCoord2d(0,1); glVertex2f(0, 240 ); //left up
                glTexCoord2d(1,1); glVertex2f(510, 240); //right up
                glTexCoord2d(1,0); glVertex2f(510, 0); //right bottom
            glEnd();
    glDisable(GL_TEXTURE_2D);*/

	Graphics::run();
	Game::run();

	glFlush(); // смена экранов (палитр)
}



void OpenGL::timer(int)
{
	display();
	glutTimerFunc(TIMER_TIMEOUT, timer, 0);
}








void OpenGL::Keyboard(unsigned char Key, int MouseX, int MouseY)
{

	Input::press_key(Key);
	/*switch (Key)
	{
	case 'w': ; break;
	case 'd': p1.dir = 'd'; break;
	case 's': p1.dir = 's'; break;
	case 'a': p1.dir = 'a'; break;
	case 'c': p1.dir = 'c'; break;
	}*/
	/* 'Key' принимает значение нажатой клавиши ('A', 'e' и т.п.),
	*       код клавиши 'ESC' (escape) - 27
	* 'MouseX' и 'MouseY' - значение координат мышки во время нажатия */
	if (Key == 27)
		exit(0); /** Выход по клавише 'Escape' - стандартной функцией 'exit'*/
}



/* Стандартная функция, вызываемая при нажатии специальных клавиш на клавиатуре */
void OpenGL::SpecialKeyboard(int Key, int MouseX, int MouseY)
{
	//static int IsFullScreen = 0, SaveW, SaveH;

	/* 'Key' принимает значение нажатой специальных клавиш:
	*    GLUT_KEY_F1, ...F12 - функциональные клавиши, а также
	*    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
	*    GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME,
	*    GLUT_KEY_END, GLUT_KEY_INSERT
	* 'MouseX' и 'MouseY' - значение координат мышки во время нажатия
	*/

}



/* Стандартная функция, вызываемая при нажатии кнопки мышки */
void OpenGL::Mouse(int Button, int State, int MouseX, int MouseY)
{
	Input::press_mouse((Button == GLUT_LEFT_BUTTON ? 1 : 2),
						(State == GLUT_DOWN ? 1 : 0),
						MouseX, MouseY);
	//if (Button == GLUT_LEFT_BUTTON)
	//{
	//	MouseButX = MouseX;
	//	MouseButY = MouseY;
	//}
	/* 'Button' принимает значения:
	*   GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
	* 'State' принимает значения:
	*   GLUT_DOWN, GLUT_UP
	* 'MouseX' и 'MouseY' - координаты курсора мышки относительно
	*   левого-верхнего угла окна
	*/
	/*if (Button == GLUT_LEFT_BUTTON)
	{
	if (State == GLUT_DOWN)
	MButtons = 1;
	else
	MButtons = 0;
	}*/
}



/* Стандартная функция, вызываемая при перемещении мышки */
void OpenGL::Motion(int MouseX, int MouseY)
{
	Input::mouse_position(MouseX, MouseY);
	/*double wz;
	int Viewport[4];
	static double ModelMatrix[16], ProjectMatrix[16];

	* 'MouseX' и 'MouseY' - координаты курсора мышки относительно
	*   левого-верхнего угла окна
	*/
	//printf("Mouse coordinates: X %4i Y %4i\r", MouseX, MouseY);

	/* Получаем матрицы преобразований и область просмотра */
	/*glGetDoublev(GL_MODELVIEW_MATRIX, ModelMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, ProjectMatrix);
	glGetIntegerv(GL_VIEWPORT, Viewport);
    Преобразуем координаты мышки в "мировые" коорлдинаты
	gluUnProject(MouseX, TSK_Height - 1 - MouseY, 0, ModelMatrix, ProjectMatrix,
	Viewport, &TSK_MX, &TSK_MY, &wz);*/
}
