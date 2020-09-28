#include <iostream>

using namespace std;

/*
const double PI = 3.14 //상수형 변수
*/

//1. 매개변수의 상수화 (모든 함수)
//2. 메서드의 상수화 (멤버 메서드) 매서드는 클래스 안의 함수

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}
	
	void Deposit (const int d) { // 매개 변수가 바뀌지 않는 상수화 하는것. 매개변수가 함수 내에서 바뀌는것을 원하지 않을 때 사용.
		//d = money;
		money += d;
		cout << d << "원을 예금했습니다." << endl;
	}
	
	void Draw(int d) {
		if(money >= d) {
			money -= d;
			cout << d << "원을 인출했습니다." << endl;
		}
	}
	
	int ViewMoney() const { // 이 함수가 클래스 내의 멤버 변수의 값을 바꾸는것을 원하지 않을 때. 메서드의 상수화 사용
		//money++;
		return money;
	}
	
private:
	int money; //private space 안에 있는 변수인 money는 public space 안에 있는 것들로만 변경이 가능하다.
};

int main() {
	Account doodle(100);
	
	doodle.Deposit(100);
	doodle.Draw(20);
	
	cout << doodle.ViewMoney() << endl;
	cout << doodle.ViewMoney() << endl;
	cout << doodle.ViewMoney() << endl;
}