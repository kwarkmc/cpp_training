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
	Polygon(const Polygon &rhs) { // 그냥 Polygon class 로 매개변수를 받을 수 없으므로 레퍼런스 형태로 매개변수를 받는다.
		nPoints = rhs.nPoints;
		points = new Point[nPoints]; // 동적할당
		for (int i = 0; i < nPoints; i++) {
			points[i] = rhs.points[i]; // 깊은복사 일어난다.
		}
		cout << "깊은 복사" << endl;
	}
	
	//이동 생성자 구현
	Polygon(Polygon &&rhs) { //r-value를 받는다.
		nPoints = rhs.nPoints;
		points = rhs.points; //복사 생성자와 다르게 동적할당을 다시 받지 않고 주소값 통채로 복사
		rhs.points = NULL;
		cout << "얕은 복사" << endl;
	}
	
	~Polygon() {
		delete[] points;
	}
	
	//복사 대입 연산자 구현
	Polygon &operator= (const Polygon &rhs) {
		if (this != &rhs) {
			nPoints = rhs.nPoints;
			delete[] points;
			points = new Point[nPoints];
			for (int i = 0; i < nPoints; i++) {
				points[i] = rhs.points[i];
			}
		}
		cout << "깊은 복사" << endl;
		return *this; //a = b = c 인경우 방지
	}
	
	//이동 대입 연산자 구현
	Polygon &operator= (Polygon &&rhs) {
		if (this != &rhs) {
			nPoints = rhs.nPoints;
			delete[] points;
			points = rhs.points;
			rhs.points = NULL; //rhs 에 있었던 애를 연결을 끊어야하므로 NULL을 대입시켜준다.
		}
		return *this;
		cout << "얕은 복사" << endl;
	}
	
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
	a = getSquare(); // 얕은 객체 복사 2회
	Polygon b = a; // 깊은 객체 복사 1회
	Polygon c;
	c = a; // 깊은 객체 복사 1회
	
	int nPoints = c.GetNPoints();
	Point *points = c.GetPoints();
	for (int i = 0; i < nPoints; i++) {
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
}