#include <vector>
#include "List.h"

typedef std::vector<Object*> ObjectVect;
typedef std::vector<Object*>::iterator ObjectVectIter;


// ********** private methods **********

List* List::unique_instance = 0;



// ********** public methods **********

Object* List::get(int i){
	check_instance();
	return unique_instance->objects_list[i];
}

int List::size() {
	check_instance();
	return unique_instance->objects_list.size();
}

void List::quick_add(Object* object){
	check_instance();
	unique_instance->objects_list.push_back(object);
}

void List::add(Object* object){
	check_instance();
	unique_instance->_add(object);
}

void List::remove(Object* object){
	check_instance();
	unique_instance->_remove(object);
}

void List::clean() {
	check_instance();
	unique_instance->_clean();
}


// ********** private methods **********

List::List() {
	objects_list.reserve(100);
}

void List::check_instance() {
	if (unique_instance == 0)
		unique_instance = new List();
}

void List::_add(Object* object){
	for(ObjectVectIter i = objects_list.begin(); i < objects_list.end(); i++)
		if (*i == object) return;
	objects_list.push_back(object);
}

void List::_remove(Object* object){
	for(ObjectVectIter i = objects_list.begin(); i < objects_list.end(); i++)
		if (*i == object) i = objects_list.erase(i);
}

void List::_clean() {
	for(int i = 0; i < objects_list.size(); i++)
		delete objects_list[i];
	objects_list.clear();
}
