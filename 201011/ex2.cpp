//정적 바인딩.

#include <iostream>

using namespace std;

class Base {
public:
	void Print() {
		cout << "From Base." << endl;
	}
};

class Derived : public Base {
public:
	void Print() {
		cout << "From Derived." << endl;
	}
};

class Derived2 : public Base {
	
};

/*
Derived d;
Base *b = &d; 예외적으로 부모 클래스의 포인터가 자식 클래스를 가리킬 수 있다.
*/

int main() {
	Base *b = new Derived(); //Derived 타입의 객체를 동적할당 하고, *b에 저장하라.
	b->Print();
	b = new Derived2();
	b->Print(); //어디에 있는 Print를 호출해야 하는지를 찾는것이 바인딩이다. 정적 바인딩->Base에 있는 Print를 실행시켜라.
	delete b;
}

//왜 Base에 있는 Print가 호출되었는가?