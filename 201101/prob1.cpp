#include <iostream>

class Point {
private:
	int x;
	int y;
public:
	Point(int pos_x, int pos_y);
};

class Geometry {
private:
	Point* point_array[100];
public:
	Geometry(Point **point_list);
	Geometry();
	
	void AddPoint(const Point &point);
	
	void PrintDistance();
}