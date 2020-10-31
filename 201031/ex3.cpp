#include <iostream>

int change_val(int &p) {
	p = 3;
	
	return 0;
}

int main() {
	int number = 5;
	
	std::cout << number << std::endl;
	change_val(number); //레퍼런스를 인자로 설정한 함수에 그냥 int형 변수인 number를 넣으면 그대로 사용할 수 있다.
	std::cout << number << std::endl;
}