// 접근 제어
// private protected public -> 접근 제어 지시자
//public	: 외부 접근 o  자식 클래스 o
//protected : 외부 접근 x  자식 클래스 o -> 자식클래스에게만 공개하고, 외부에는 공개하지 않음
//private	: 외부 접근 x  자식 클래스 x

#include <iostream>

using namespace std;

class Base {
public:
	int bPublic;
protected:
	int bProtected;
private:
	int bPrivate;
};

class Derived : public Base { //protected로 상속을 바꾸면 public 멤버가 protected 멤버로 변한다! 공개 수준이 더 광범위한 멤버들을 protected로 공개 수준을 낮추는것.
public:
	int dPublic;
	
	void DFunc() {
		bPublic = 1;
		bProtected = 1;
		// bPrivate = 1; 접근 안됨.
		dPublic = 1;
		dPrivate = 1;
	}
private:
	int dPrivate;
};

int main() {
	Base b;
	Derived d;
	
	b.bPublic = 1;
	//b.bProtected = 1;
	//b.bPrivate = 1;
	
	d.bPublic = 1;
	//d.bProtected = 1;
	//d.bPrivate = 1;
	d.dPublic = 1;
	//d.dPrivate = 1;
	
}