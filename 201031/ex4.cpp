#include <iostream>

int main() {
	int arr[3] = {1, 2, 3};
	int(&ref)[3] = arr; // &ref[3] 인 배열 각각이 arr 배열의 순서에 맞는 메모리들을 각각 지정하고 있기 때문에, 가능하다. 하나의 레퍼런스 변수로 모든 배열을 가르키는것은 불가능하다.
	
	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;
	
	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}