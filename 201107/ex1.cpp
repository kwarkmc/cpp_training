#include <iostream>

class A {
private:
	int x;
public:
	A(int c) : x(c) {}
	
	int& access_x() { return x; } //x의 레퍼런스를 리턴
	int get_x() { return x; } //x를 리턴
	void show_x() {
		std::cout << x << std::endl;
	}
};

int main() {
	A a(5);
	a.show_x();
	
	int& c = a.access_x(); // c는 x의 레퍼런스 == 별명 을 받았다. 레퍼런스를 리턴하는 함수는 그 함수 부분을 원래의 변수로 치환해도 상관 없다. int &c = x와 같은 의미.
	c = 4;
	a.show_x();
	
	int d = a.access_x(); //d는 c와는 다르게 x의 별명이 아니라, x의 값을 복사한 독립적인 변수이므로, d=3을 해도 객체 안의 x는 바뀌지 않는다.
	d = 3;
	a.show_x();
	
	/*
	int& e = a.get_x();
	e = 2;
	a.show_x();
	*/
	
	int f = a.get_x(); // 임시로 생성된 int 변수 x' 가 f 에 복사되는데 f를 변경한다고 객체 a의 x 에게는 영향을 끼칠 수 없다.
	f = 1;
	a.show_x();
}