//다음 프로그램의 출력 결과는?

#include <iostream>

using namespace std;

int n = 0;
namespace A {
	int n = 0;
	namespace B {
		void set() { n = 10; }
		int n = 0;
	}
}

namespace C {
	void set();
	int n = 0;
}

void C :: set() { n = 20; }

int main() {
	using namespace A::B;
	
	set(); //using namespace A::B 코드를 넣었으므로 컴파일러는 A::B 안에 set 함수가 있는지 찾을 것이다. -> namespace B 안에 set 이 있으므로 namespace A 안에 있는 n 이 10으로 바뀐다.
	C::set(); //namespace 가 C 라고 명시되어 있으므로 namespace C 안에 있는 set 함수를 실행하여  namespace C 안에 있는 n 이 20으로 바뀐다.
	
	cout << ::n << endl;
	cout << A::n << endl;
	cout << A::B::n << endl;
	cout C::n << endl;
}