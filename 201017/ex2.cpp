#include <iostream>

using namespace std;

double PI = 3.1415926535;

class Circle {
public:
	Circle(double r) : r(r) {}
	
	double GetArea() {
		return PI * r * r;
	}
	
	void Resize(double f) {
		r *= f;
	}
private:
	double r;
};

class Rectangle {
public:
	Rectangle(double a, double b) : a(a), b(b), {}
	
	double GetArea() {
		return a*b;
	}
	
	void Resize(double f) {
		a *= f;
		b *= f;
	}
	
private:
	double a, b;
};

int main() {
	
}