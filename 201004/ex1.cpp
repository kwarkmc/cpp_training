//묵시적, 암시적 형 변환 implicit conversion
//명시적 형 변환 explicit conversion

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	Item(int num) : num(num) { // 생성자가 int 형을 Item Class 로 변환해주는 역할도 하고 있다. (변환 생성자)
		cout << "Item(int)" << endl;
	}
	Item(string name) : name(name) {
		cout << "Item(string)" << endl;
	}
	Item(int num, string name) : num(num), name(name) {
		cout << "Item(int, string)" << endl;
	}
	
	void print() {
		cout << num << " : " << name << endl;
	}
	
private:
	int num;
	string name;
};

int main() {
	Item i1 = Item(1);
	Item i2(2);
	Item i3 = 3;
	i3 = 3; // 여기서의 대입연산자는 이동대입연산자 (moving sematrics) 가 된다. 왜일까?
	// 컴파일 중, 정수 3이 Item Class 로 변환이 가능하다면, 변환 생성자를 호출한다. (새로운 임시 객체를 만들었다.) 임시객체(num = 3, name = NULL) 임시객체에서 i3로 얕은 복사가 완료되면, 임시객체는 사라진다. (묵시적 형 변환)
	Item i4 = (Item)4; // (명시적 형 변환)
	
	Item i5(5);
	i5 = string("stone"); // (string)"stone"
	Item i6 (1, "grass");
	Item i7 = {2, "dirt"}; // Item i3 = 3 와 같은 상태이다.
	i7 = {2, "dirt"}; // 매개변수가 두 개인 상황에서 묵시적 변환을 쓰고싶을 때 사용
	Item i8 {3, "wood"};
	
	i1.print();
	i2.print();
	i3.print();
	i4.print();
	i5.print();
	i6.print();
	i7.print();
	i8.print();
}