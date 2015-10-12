#include "Snake.h"
#include "..\Global.h"
#include "..\List.h"
#include "..\Input.h"
#include "Apple.h"
#include "Wall.h"
#include "SnakeInput.h"
#include "..\Collision.h"
#include "AppleWallBuilder.h"
#include <iostream>

/// ********* public methods ************

Snake::Snake() {
	play_again();
	repeat_flag = false;
	Input::set(new SnakeInput(this));
}

void Snake::run() {
	head->draw();
	if (repeat_flag) {
		repeat_flag = false;
	}
	if (head->paused()) return;
	head->move();
	try {
        SnakeElement* element = get_last_element();
        element->set_position(head->position);
        elements.push(element);
	} catch (int error_code) {
		play_again();
	}
}

void Snake::redirect(Direct direct){
	head->redirect(direct);
}


/// *********** private methods **************


SnakeElement* Snake::get_last_element() {
	Object* find = Collision::collise(head);
	SnakeElement* element = (elements.front());
	if (find != head){
        //std::cout << "collision registered\n";
		if (find->color == green) { // its apple
			dynamic_cast<Apple*>(find)->eated();
			element = build_element();
			if (elements.size() > 100) win();
		}
		else if (find->color == blue) { //its wall
            lose();
            throw -1;
		}
		else if (find->color == red) { //its snake element
			lose();
			throw -2;
		}
	}
	if (element == elements.front()) elements.pop();
	return element;
}

Object* Snake::get_collised() {
	return Collision::collise(head);;
}

void Snake::win() {
	repeat_flag = true;
    std::cout << "You win!\n";
	// play_again();
}

void Snake::lose() {
	repeat_flag = true;
	std::cout << "You lose.\n";
	//play_again();
}

void create_walls() {
    Point p(-cell_size/2, HEIGHT/2);
	Object* object = new Wall(p, cell_size, HEIGHT);
	p = Point(WIDTH + cell_size/2, HEIGHT/2);
	object = new Wall(p, cell_size, HEIGHT);
	p = Point(WIDTH/2, -cell_size/2);
	object = new Wall(p, WIDTH, cell_size);
	p = Point(WIDTH/2, HEIGHT+cell_size/2);
	object = new Wall(p, WIDTH, cell_size);

	p = Point(WIDTH/cell_size/2*cell_size+cell_size/2, HEIGHT/cell_size/2*cell_size+cell_size/2);
	object = new Apple(p, cell_size);
	p = Point(WIDTH/2+cell_size/2, HEIGHT/2+cell_size/2);
}

void Snake::play_again() {
	List::clean(); // erase all objects and allocate memory
	while (!elements.empty()) elements.pop(); // clear element queue.
	head = new SnakeHead({cell_size/2, cell_size/2});
	// TODO AppleWallBuilder::run();
	elements.push(build_element());
	create_walls();
}

SnakeElement* Snake::build_element() {
	return new SnakeElement(head->position, cell_size, cell_size, red);
}
