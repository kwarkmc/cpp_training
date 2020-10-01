#include <iostream>

using namespace std;

class Vector2 {
public:
	Vector2() : x(0), y(0) { //생성자
		cout << this << " : Vector2()" << endl;
	}
	Vector2(const float x, const float y) : x(x), y(y) {
		cout << this << " : Vector2(const float x, const float y)" << endl;
	}
	
	~Vector2() {
		cout << this << " : ~Vector2()" << endl; //소멸자
	}
	
	float GetX() const { return x; }
	float GetY() const { return y; }
	
private:
	float x;
	float y;
};

int main() {
	Vector2 *d1 = new Vector2();
	Vector2 *d2 = new Vector2(3, 2);
	
	cout << "(" << d1->GetX() << " , " << d1->GetY() << ")" << endl;
	cout << "(" << d2->GetX() << " , " << d2->GetY() << ")" << endl;
	
	delete d1;
	delete d2;
}