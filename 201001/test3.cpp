#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() : num(cnt++), ch('\0') { } //cnt++ 은 후위 증가 식이므로 num에 cnt 에 있는 값을 대입시키고 1이 더해진다.
	
	void Check(MyClass *ptr) { // ptr = &obj[0]
		if(ptr + num == this) { // ptr+num = &ptr[num]
			cout << num << endl;
		}
	}
	static int cnt; //초기값이 0인 정적 변수
private:
	int num;
	char ch;
};
int MyClass::cnt = 0;

int main() {
	MyClass obj[5]; // obj 의 첫번째 값이 포인터
	
	cout << "Test #1 : " << endl;
	for(int i = 0; i < 5; i++) {
		obj[i].Check(obj);
	}
	cout << "Test #2 : " << endl;
	for (MyClass &i : obj) { // i는 레퍼런스 변수.
		i.Check(obj);
	}
	cout << "cnt = " << MyClass::cnt << endl;
}