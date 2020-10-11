//override : 우선하다.
//overwrite : 덮어쓰다.

#include <iostream>

using namespace std;

class Base {
public:
	int a = 10; //생성자가 호출될 때 자동으로 실행되며 a를 10으로 초기화한다.
	void Print() {
		cout << "From Base." << endl;
	}
};

class Derived : public Base {
public:
	int a = 20; //Derived.a 를 호출하면, 부모 클래스에도 a가 있고, 자식 클래스에도 a 가 있기 때문에, 모호해진다. 그냥 d.a를 호출하면 Derived에 있는 a 가 먼저 호출된다.
	void Print() {
		cout << "From Derived." << endl;
	}
};

int main() {
	Base b;
	Derived d;
	
	cout << b.a << endl;
	cout << d.a << endl; // == d.Derived::a
	cout << d.Base::a << endl;
	
	d.Print();
	d.Base::Print();
	d.Derived::Print();
}