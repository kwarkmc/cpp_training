#include <iostream>

using namespace std;

class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bingsoo()" << endl;
		ice = new Ice;
	}
	virtual ~Bingsoo() {
		cout << "~Bingsoo()" << endl;
		delete ice;
	}
	
private:
	Ice *ice;
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() {
		cout << "PatBingsoo()" << endl;
		pat = new Pat;
	}
	~PatBingsoo() {
		cout << "~PatBingsoo()" << endl;
		delete pat;
	}
private:
	Pat *pat;
};

int main() {
	Bingsoo *p = new PatBingsoo; 
	delete p; // Bingsoo 의 소멸자를 vritual로 가상 소멸자로 만드니까, 컴파일러는 Bingsoo 타입인 p를 소멸시켜야 하는데 Bingsoo의 소멸자는 가상소멸자 이므로 PatBingsoo 의 소멸자를 호출한다.
}