#include <cstring>
#include <iostream>

using namespace std;

class String {
public:
	String() {
		cout << "String() : " << this << endl;
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "String(const char*) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	String(const String &rhs) { // 복사 생성자
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}
	
	String(String &&rhs) { //매개변수가 r-value가 되면, String res 가 임시객체로 복사가 될 때 호출된다.
		cout << "String(String&&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData; // 얕은 복사
		rhs.strData = NULL;
	}
	
	~String() {
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;
	}
	
	String &operator=(const String &rhs) { // 복사 대입 연산자
		cout << "String &operator=(const String &) : " << this << endl;
		if(this != &rhs) {
			release();
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;
	}
	
	String &operator=(String &&rhs) {
		cout << "String &operator=(String &&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData; // 얕은 복사
		rhs.strData = NULL;
		return *this; // String a = b= c; 와 같이 연쇄적인 대입연산자를 처리하기 위해 return *this 추가.
	}
	
	char *GetStrData() const {
		return strData;
	}
	
	int GetLen() const {
		return len;
	}
	
	void SetStrData(const char *str) {
		cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	
private:
	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData allocated : " << (void *)strData << endl;
	}
	
	void release() {
		delete[] strData;
		if (strData) cout << "strData released : " << (void*)strData << endl;
	}
	
	char *strData;
	int len;
};

//깊은 복사가 실행 될 때 마다 strcpy 함수를 통해 모든 배열의 요소들을 복사한다. 시간이 많이 걸린다. 또한, 깊은 복사가 필요가 없고 얕은 복사만으로도 충분한 경우가 있다.

String getName() {
	cout << "===== 2 =====" << endl;
	String res("Doodle");
	
	/*여러가지 작업 코드*/
	
	cout << "===== 3 =====" << endl;
	return res;
	//res 를 return 하는 순간 String res 는 없어지고 소멸자가 호출된다. 그런데, return 된 res 를 a에 복사해야 하므로 res는 이름이 없는 임시 객체에 복사되었다가, a 에 복사가 완료되면 임시 객체는 사라진다. -> 복사는 깊은 복사가 2번 일어난다. (과연 이 2번의 깊은 복사는 필요한가?)
	/*
	a = getName(); 코드가 실행됨에 따라 일어나는 일
	res.strData
		복사 1 (복사 생성자에 의해) -> 복사 생성자에 의해 깊은 복사가 일어나지 않고, 얕은 복사에 의해 주소만 임시 객체로 복사되어도 충분히 목표를 이룰 수 있다. (효율 상승)
	임시객체.strData
		복사 2 (복사 대입 연산자에 의해) -> 복사 대입 연산자에 의해 깊은 복사가 일어나지 않고, 얕은 복사에 의해 주소만 임시객체에서 a 로 복사되어도 충분히 목표를 이룰 수 있다. (효율 상승)
	a.strData
	*/
	//얕은 복사를 하되, 메모리 해제가 두번 일어나지 않고, 한번만 일어나게 할 수 있을까? -> 이동 시맨틱
}

int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;
	
	String &&r = getName(); //&&r : r-value 참조자.
	
	//r-value 등호의 우변에만 올 수 있는 값들. 연산의 결과값은 r- value 다. 함수의 return 값도 r- value 다. 결국 : 임시객체는 모두 r-value 다.
}
