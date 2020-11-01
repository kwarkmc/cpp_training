#include <iostream>

void print(int x) {
	std::cout << "int : " << x << std::endl;
}
/*
void print(char x) {
	std::cout << "char : " << x << std::endl;
}
*/

//자신과 맞는 타입의 변수가 없을 경우, char, short -> int , Float -> double로 변환된다. 컴파일러가 변환을 할 수 없을경우 모호하다(ambiguous) 하다고 판단하여 오류 발생.
void print(double x) {
	std::cout << "double : " << x << std::endl;
}

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;
	
	print(a);
	print(b);
	print(c);
	
	return 0;
}