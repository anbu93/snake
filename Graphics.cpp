#include "Graphics.h"
#include "List.h"



// ********** fields **********

Graphics* Graphics::unique_instance = 0;



// ********** public methods **********

void Graphics::run() {
	check_instance();
	for(int i = 0; i < List::size(); i++)
		List::get(i)->draw();
}



// ********** private methods **********

void Graphics::check_instance() {
	if (unique_instance == 0)
		unique_instance = new Graphics();
}

Graphics::Graphics() {}
