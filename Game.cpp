#include "Game.h"



// ********** fields **********

Game* Game::unique_instance = 0;



// ********** public methods **********

void Game::set_scene(Scene* _scene) {
	check_instance();
	if (_scene != 0) unique_instance->scene = _scene;
}

void Game::run() {
	check_instance();
	if (unique_instance->scene != 0)
		unique_instance->scene->run();
}



// ********** private methods **********

Game::Game()
: scene(0) {
}

void Game::check_instance() {
	if (unique_instance == 0)
		unique_instance = new Game();
}
