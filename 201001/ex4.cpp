//깊은 복사, 얕은 복사

#include <iostream>

using namespace std;

int main() {
	int *a = new int(5);
	int *b = new int(3);
	
	//내가 원하는 것은 b 의 값 3을 a 에 저장하는 것인데
	a = b; //얕은 복사 (참조만 복사)
	//평소대로 사용하면, 변수 안의 값이 바뀌는 것이 아니라, 주소 자체가 바뀌면서 포인터 a 가 가르키고 있던 대상이 b 가 가르키고 있던 3이 들어있는 메모리로 바뀐다.(주소값이 바뀐다) 5가 들어있던 메모리는 방치
	*a = *b; //깊은 복사 (값을 복사)
	delete a;
	delete b;
}