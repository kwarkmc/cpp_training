//Static Allocation (정적 할당) int a;
//Dynamic Allocation (동적 할당) : 프로그램 실행 중에 변수를 메모리에 할당하는것.
//시간, 공간(Memory)

#include <iostream>

using namespace std;

int main() {
	int *a = new int(5); // 우변에서 new 연산자는 메모리에 int 형 공간을 할당하고, 거기에 5를 넣는다. 그 메모리의 주소를 return 한다. 좌변은 new 연산자로부터 return 받은 주소를 포인터 a 에 저장한다.
	cout << a << endl;
	cout << *a << endl;
	
	*a = 10;
	cout << a << endl;
	cout << *a << endl;
	
	delete a;
}

