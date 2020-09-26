#include <iostream>

using namespace std;

//생성자 : 멤버 변수를 초기화
//소멸자 : 메모리 해제

//복소수 저장하는 class (real, imag)


class Complex {
public:
	Complex() { // 생성자도 함수이므로 Overloading 가능
		real = 0;
		imag = 0;
	}
	Complex(double real_, double imag_) {
		real = real_;
		imag = imag_;
	}
	double GetReal() {
		return real;
	}
	void SetReal(double real_) {
		real = real_;
	}
	double GetImag() {
		return imag;
	}
	void SetImag(double imag_) {
		imag = imag_;
	}
	
private:
	double real;
	double imag;
};

int main() {
	Complex c1; // 매개변수가 없는 생성자가 실행된다.
	Complex c2 = Complex(2, 3); // 매개변수가 있는 생성자가 실행된다.
	Complex c3(2, 3);
	Complex c4 = {2,3};
	Complex c6 {2,3};
	
	cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
	cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
	cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
}