#include <iostream>

using namespace std;

class String {
public:
	String() { //선언만 해 놓은 경우, 동적할당을 하지 않는것이 좋다.
		strData = NULL; //이 포인터가 아무것도 가르키고 있지 않다.
		len = 0;
	}
	String(const char *str) {
		len = strlen(str);
		strData = new char[len + 1]; //NULL 문자까지 고려하여 동적할당 해 주어야 한다.
		strcpy(strData, str); // 깊은 복사
	}
	
	~String() {
		delete[] strData;
	}
	
	char *GetStrData() const {
		return strData;
	}
	
	int GetLen() const {
		return len;
	}
private:
	char *strData; //문자열이 동적할당 된 주소
	int len;
};

int main() {
	String S;
}