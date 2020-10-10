//상속 -> 부모 클래스의 멤버들을 자식 클래스에 상속해주는것. 부모와 자식 클래스 모두에 같은 멤버들이 들어있다. 자식 클래스는 상속받은 부모 클래스의 멤버들과 자신만의 멤버를 가질 수 있다. 또한, 상속이 일어났을때 자식 클래스는 부모 클래스에 속하게 된다.

#include <iostream>

using namespace std;

class Base {
public:
	void bFunc () {
		cout << "Hello!" << endl;
	}
	
	int bNum;
};

class Derivd : public Base { // Derivd는 Base 클래스를 부모 클래스로 하는 클래스다.
public:
	void dFunc () {
		cout << "Hello?" << endl;
	}
	
	int dNum;
};

int main() {
	Base b;
	Derivd d;
	
	b.bFunc();
	b.bNum = 1;
	
	d.bFunc();
	d.bNum = 2;
	d.dFunc();
	d.dNum = 1;
}