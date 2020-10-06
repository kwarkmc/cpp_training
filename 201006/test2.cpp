#include <iostream>

using namespace std;

int main() {
	int a = 10, b = 20, c = 30;
	int *p = &a;
	int &r = b; // 레퍼런스 변수는 특별한 케이스가 아니면 그냥 INT 형으로 봐도 된다.
	int **pp = &p;
	int* (&rp) = p; // p라는 포인터를 가르키는 레퍼런스 변수
	
	r = c / *p;
	rp = &c; //rp는 포인터를 가르키는 레퍼런스 변수이므로 그냥 포인터라고 생각하고 c의 주소값을 대입해준다.
	**pp = 40;
	*p = 50;
	*pp = &a;
	*rp = 60;
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << *p << endl;
	cout << r << endl;
	cout << **pp << endl;
	cout << *rp << endl;
}