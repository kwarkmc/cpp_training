//연산자 overloading
//vector
//멤버 method

//멤버 메서드의 선언, 정의 분리하기.

#include <iostream>

using namespace std;

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);
	
	float GetX() const; //const 로 해결이 되는 모든 함수는 넣어주는것이 좋다.
	float GetY() const;
private:
	float x;
	float y;
};

Vector2 Sum(Vector2 a, Vector2 b) {
	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
} // vector 클래스 끼리의 연산을 위해 벡터 연산을 해 return 해주는 전역함수를 만들었다. / 전역변수, 함수는 객체 지향 프로그래밍에서 없애는것이 가장 좋으므로 class 안으로 집어넣을 것이다.

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c = Sum(a, b);
	
	cout << a.GetX() << "," << a.GetY() << endl;
	cout << b.GetX() << "," << b.GetY() << endl; // Get 함수도 함수이므로 함수명 뒤 괄호를 꼭 붙여줘야한다! 잦은 실수 부분
	cout << c.GetX() << "," << c.GetY() << endl;
}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }