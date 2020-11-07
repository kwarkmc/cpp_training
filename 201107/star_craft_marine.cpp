#include <iostream>

class Marine {
private:
	static int total_marine_num; // static 변수는 소멸자가 생성될때 없어지는것이 아니라, 프로그램이 종료될때 까지 남아있다가 없어진다. + 클래스로 선언한 어떤 객체에 존재하는것이 아니라, 클래스 그 자체에 종속되는것이다.
	const static int i = 0;
	
	int hp;
	int coord_x, coord_y;
	bool is_dead;
	
	const int default_damage;
public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);
	~Marine() { total_marine_num--; }
	
	int attack() const;
	Marine& be_attacked(int damage_earn);
	void move(int x, int y);
	
	void show_status();
	static void show_total_marine();
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() {
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; } // 초기화 리스트 (initializer list) 생성자 호출과 동시에 멤버 변수들을 초기화해준다.

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) { total_marine_num++; }

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) { total_marine_num++; }
// 생성자에서 초기화하는 멤버변수와 그 인수의 이름이 같아도 상관 없다.


void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() const { return default_damage; } // 상수 멤버 함수. 상수 멤버 함수 안에서는 객체들의 '읽기'만이 수행될 수 있다.

Marine& Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
	
	return *this; // this는 객체 자신을 가리키는 포인터의 역할을 한다.
	
	/*
	this->hp -= damage_earn;
	if(this->hp <= 0) this->is_dead = true;
	
	return *this;
	와 같은 의미의 코드이다.
	*/
	
}

void Marine::show_status() {
	std::cout << "*** Marine ***" << std::endl;
	std::cout << "Location : ( " << coord_x << " , " << coord_y << " )" << std::endl;
	std::cout << "HP : " << hp << std::endl;
	std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
	Marine marine3(10, 10, 4);
	marine3.show_status();
}

int main() {
	Marine marine1(2, 3, 5);
	Marine::show_total_marine(); // static 함수는 객체가 아닌 클래스 자체에 종속되어있는 것이기 때문에 호출하는 방법이 다르다.
	
	Marine marine2(3, 5, 10);
	Marine::show_total_marine();
	
	std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;
	marine2.be_attacked(marine1.attack());
	
	marine1.show_status();
	marine2.show_status();
}

//4-4