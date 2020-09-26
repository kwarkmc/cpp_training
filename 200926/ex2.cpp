//this 포인터

#include <iostream>

using namespace std;

class MyClass {
public:
	void PrintThis() {
		cout << "나의 주소는 " << this << endl; // this 포인터를 사용하면 명령어가 속한 구조체의 주소값을 알 수 있다.
		// MyClass 클래스와 PrintThis 함수는 메모리에서 서로 다른 위치에 존재하지만, this 포인터는 PrintThis 함수 내에 있음에도 불구하고 MyClass 클래스의 주소값을 반환한다.
	}
};

int main() {
	MyClass a, b;
	
	cout << "a의 주소는 " << &a << endl;
	cout << "b의 주소는 " << &b << endl;
	
	a.PrintThis();
	b.PrintThis();
}