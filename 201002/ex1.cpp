#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
	String() {
		cout << "String( ) 생성자 호출" << endl;
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "String(const char *) 생성자 호출" << endl;
		len = strlen(str);
		strData = new char[len + 1]; // NULL 문자 고려
		cout << "strData 할당 : " << (void*)strData << endl; //void 포인터는 strData 배열에 대한 주소값은 가지고 있지만 그 포인터가 가르키고 있는게 배열인지에 대한 정보는 가지고 있지 않다.
		strcpy(strData, str); // 깊은 복사
	}
	~String() {
		cout << "~String 소멸자 호출" << endl;
		delete[] strData;
		cout << "strData 해제됨 : " << (void*)strData << endl;
		strData = NULL;
	}
	
	char *GetStrData() const {
		return strData;
	}
	
	int GetLen() const {
		return len;
	}
	
private:
	char *strData;
	int len;
};

int main() {
	String s1("안녕");
	String s2(s1); // s2 = s1 과 같은 의미
	
	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
}