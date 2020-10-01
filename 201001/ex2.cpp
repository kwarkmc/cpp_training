#include <iostream>

using namespace std;

int main() {
	//동적할당을 사용하면 사용자가 사용할 만큼의 배열을 알맞게 설정할 수 있다.
	int *arr;
	int len;
	
	cout << "동적할당 할 배열 길이 입력 : ";
	cin >> len;
	
	arr = new int[len]; //arr 에는 len 만큼의 길이가 동적할당 된 배열의 첫 번째 칸의 주소값이 대입된다.
	
	for (int i = 0; i < len; i++) {
		arr[i] = len - 1;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
	
	delete[] arr; // 배열 전체를 한번에 해제할 때는 delete[] 를 사용한다.
}