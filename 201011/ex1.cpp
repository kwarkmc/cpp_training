//override : 우선하다.

#include <iostream>

using namespace std;

class Base {
public:
	int a = 10; //생성자가 호출될 때 자동으로 실행되며 a를 10으로 초기화한다.
};

class Derived : public Base {
public:
	int a = 20;
};

int main() {
	Base b;
	Derived d;
	
	cout << b.a << endl;
	cout << d.a << endl;
}