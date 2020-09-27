#include <iostream>

using namespace std;

// 생성자 : 멤버 변수 초기화

class Complex {
public:
	Complex() : real(0), imag(0) { } // 생성자도 함수로 볼 수 있으므로 Overloading 이 가능하다.
	// 어차피 real_도 0, imag_ 도 0이므로 default 매개변수를 사용하면 그냥 생략할 수 있다.
	// 초기화 목록 사용 간소화
	
	Complex(double real_, double imag_) : real(real_), imag(imag_) { } // default 매개변수 : 함수 내 매개변수가 있으면 맨 오른 쪽 부터 default 매개변수를 줄 수 있다.
		
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
	
	
	Complex c1;
	Complex c2 = Complex(2, 3);
	Complex c3 (2, 3);
	Complex c4 = {2, 3};
	Complex c5 = Complex {2, 3};
	Complex c6 {2, 3};
	
	cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
	cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
	cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
}