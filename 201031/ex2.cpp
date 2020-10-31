#include <iostream>

int main() {
	int a = 3;
	int& another_a = a; // a의 레퍼런스인 another_a를 만들어주었다.
	//레퍼런스는 포인터와 다르게, int& another_a; 로는 단독으로 쓸 수 없다.
	
	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	
	return 0;
}

//another_a 가 a의 레퍼런스 이기 때문에, 컴파일러에서는 another_a 가 a의 또다른 이름이라고 인식하고 있는것이다.