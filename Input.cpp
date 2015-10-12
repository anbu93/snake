#include "Input.h"

Input* Input::unique_instance = 0;

/// ********** public methods **********

void Input::press_key(unsigned char key){
	check_instance();
	unique_instance->_press_key(key);
}

void Input::press_mouse(int key, int stat, int x, int y){
	check_instance();
	unique_instance->_press_mouse(key, stat, x, y);
}

void Input::mouse_position(int x, int y){
	check_instance();
	unique_instance->_mouse_position(x, y);
}

void Input::set(Input* input){
	if (unique_instance && input) delete unique_instance;
	unique_instance = input;
}



/// ************ Mocks **********
/// #include <iostream>

void Input::_press_key(unsigned char key){
    /// std::cout << key << " ";
}

void Input::_press_mouse(int key, int stat, int x, int y){
	/// std::cout << key << "(" << stat << ")" << x << "-" << x << " ";
}

void Input::_mouse_position(int x, int y){
	/// std::cout << x << "-" << y << " ";
}



/// *************** private methods ***************

void Input::check_instance() {
	if (!unique_instance) unique_instance = new Input();
}

Input::Input() {}

Input::~Input() {
	delete unique_instance;
}
