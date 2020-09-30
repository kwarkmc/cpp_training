//연산자 overloading
//vector
//멤버 method

//멤버 메서드의 선언, 정의 분리하기.

#include <iostream>

using namespace std;

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y); //늘 정의를 분리해 놓는것이 좋다.
	
	float GetX() const; //const 로 해결이 되는 모든 함수는 넣어주는것이 좋다.
	float GetY() const;
	
	Vector2 operator+(const Vector2 rhs) const;
	Vector2 operator-(const Vector2 rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	float operator*(const Vector2 rhs) const;
	
private:
	float x;
	float y;
};

	Vector2 Sum(Vector2 a, Vector2 b) { 
		return Vector2(a.GetX() + b.GetX() , a.GetY() + b.GetY());
	} 

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c1 = a + b;
	Vector2 c2 = a.operator+(b); // 메서드에 operator+ 라는 이름을 주었을때 연산자 + 로 사용할 수 있다. (연산자 오버로딩)
	Vector2 c3 = a + b;
	Vector2 c4 = a - b;
	Vector2 c5 = a * 1.6;
	Vector2 c6 = a / 2;
	float c7 = a * b;
	
	cout << a.GetX() << "," << a.GetY() << endl;
	cout << b.GetX() << "," << b.GetY() << endl; // Get 함수도 함수이므로 함수명 뒤 괄호를 꼭 붙여줘야한다! 잦은 실수 부분
	cout << c1.GetX() << "," << c1.GetY() << endl;
	cout << c2.GetX() << "," << c2.GetY() << endl;
	cout << c3.GetX() << "," << c3.GetY() << endl;
	cout << c4.GetX() << "," << c4.GetY() << endl;
	cout << c5.GetX() << "," << c5.GetY() << endl;
	cout << c6.GetX() << "," << c6.GetY() << endl;
	cout << c7 << endl;
}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

Vector2 Vector2::operator+(const Vector2 rhs) const {
	return Vector2(x + rhs.x, y + rhs.y); // 동적이어서 미리 자신이 가지고 있는것에 어떤것을 더할 것인지 입력 메서드임과 동시에 연산자의 역할을 수행한다.
}

Vector2 Vector2::operator-(const Vector2 rhs) const {
	return Vector2(x - rhs.x , y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
	return Vector2(x * rhs , y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
	return Vector2(x - rhs , y - rhs);
}

float Vector2::operator*(const Vector2 rhs) const {
	return (x * rhs.x + y * rhs.y);
}