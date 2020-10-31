#include <iostream>

/*
int& function() {
	int a = 2;
	return a;
}

int main() {
	int b = function();
	return 0;
}
*/

//function이 레퍼런스를 리턴하면서, 원래 참조하고 있던 변수는 이미 사라지고 없으므로, 레퍼런스는 있는데 원래 참조한 것이 없어진것을 댕글링 레퍼런스 (Dangling Reference) 라고 한다. 

//레퍼런스를 리턴하는 함수에서 지역변수의 레퍼런스를 리턴하지 않도록 해야한다.

int& function(int& a) { //위와 다르게, 인자로 받은 레퍼런스를 그대로 리턴한다. function 안에 있는 a 는 main 내의 b를 참조하는것이므로, function 에서는, 아직 살아있는 변수인 b를 계속 참조하는 것이다.
	a = 5;
	return a;
}

int main() {
	int b = 2;
	int c = function(b);
	return 0;
}