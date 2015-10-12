#ifndef LIST_H
#define LIST_H

#include "Object.h"
#include <vector>

class List {
private:
	std::vector<Object*> objects_list;
	static List* unique_instance;
public:
	static Object* get(int i);
	static int size();
	static void quick_add(Object* object);
	static void add(Object* object);
	static void remove(Object* object);
	static void clean();
private:
	List();
	static void check_instance();
	void _add(Object* object);
	void _remove(Object* object);
	void _clean();
};

#endif
