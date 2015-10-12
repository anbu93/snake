#include "SnakeInput.h"

SnakeInput::SnakeInput(Snake* snake)
: snake(snake) {}

void SnakeInput::_press_key(unsigned char key){
	Direct direct = direct;
	switch(key){
		case 'Ц':
		case 'ц':
		case 'W':
		case 'w':
			direct = up; break;
		case 'Ы':
		case 'ы':
		case 'S':
		case 's':
			direct = down; break;
		case 'Ф':
		case 'ф':
		case 'A':
		case 'a':
			direct = left; break;
		case 'В':
		case 'в':
		case 'D':
		case 'd':
			direct = right; break;
		case 'З':
		case 'з':
		case 'P':
		case 'p':
			direct = none; break;
		default: return;
	}
	snake->redirect(direct);
}
