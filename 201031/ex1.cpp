//참조자의 도입
#include <iostream>

int change_val (int *p) {
	*p = 3;
	
	return 0;
}

int main() {
	int number = 5;
	
	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}

//일반 C 에서는, 어떠한 변수를 가리키고 싶을 때 포인터를 사용했다.
//그러나 C++ 에서는 변수나 상수를 가르키는 다른 방법인 참조자 (레퍼런스 - reference) 를 사용할 수 있다.