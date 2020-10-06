#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

class Polygon {
public:
	Polygon() {
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point *points) : nPoints(nPoints) {
		this->points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			this->points[i] = points[i];
		}
	}
	
	//복사 생성자 구현
	
	//이동 생성자 구현
	
	~Polygon() {
		delete[] points;
	}
	
	//복사 대입 연산자 구현
	
	//이동 대입 연산자 구현
	
	int GetNPoints() const {
		return nPoints;
	}
	
	Point *GetPoints() const {
		if(nPoints == 0) {
			return NULL;
		}
		return points;
	}
	
private:
	int nPoints;
	Point *points;
};

Polygon getSquare() {
	Point points[4] = { {0, 0}, {1, 0}, {1, 1}, {0, 1} };
	Polygon p(4, points);
	return p;
}

int main() {
	Polygon a;
	a = getSquare();
	Polygon b = a;
	Polygon c;
	c = a;
	
	int nPoints = c.GetNPoints();
	Point *points = c.GetPoints();
	for (int i = 0; i < nPoints; i++) {
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
}