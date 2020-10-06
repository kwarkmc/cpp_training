#include <iostream>

using namespace std;

int main() {
	char str[] = "Hello, World!";
	char *p_str = str;
	
	cout << p_str << endl;
	cout << *p_str << endl; // 첫 번째 포인터의 참조값만 출력이 된다.
}

//cout 에 char가 들어있는 포인터를 넣으면 그 문자열이 모두 출력되고, char가 들어있는 포인터의 참조값을 넣으면 그 포인터 하나의 참조값만 프린트된다.