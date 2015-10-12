#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(int x, int y) : x(x), y(y) {}
	Point() : x(0), y(0) {}
	int x;
	int y;
};

#endif
