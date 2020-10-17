#include <iostream>

using namespace std;

class A {
public:
	virtual void f() = 0; // 순수 가상 함수. a->f() 에서 실제 어디있는 a 이냐에 따라 실행될 f() 가 결정된다 (동적 바인딩)
};

class B : public A {
public:
	void f() {
		cout<< "B::f()" << endl;
	}
};

int main() {
	A *a = new B; // A라는 클래스에서 순수 가상함수를 하나라도 가지고 있다면 객체를 만들 수 없다. 추상 클래스.
	a->f();
	delete a;
}