#include <iostream>
#include <string.h>

class Photon_Cannon {
private:
	int hp;
	int shield;
	int coord_x;
	int coord_y;
	int damage;
	char *name;
public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char *cannon_name);
	Photon_Cannon(const Photon_Cannon& pc); //복사 생성자 (copy constructor) , 다른 Photon_Cannon 의 객체를 상수 레퍼런스로 받는다는 의미. const 가 붙었으므로 복사 생성자 내부에서는 pc 의 데이터를 변경할 수 없고, 복사의 용도로만 사용할 수 있다.
	~Photon_Cannon();
	
	void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출!" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
	
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "생성자 호출!" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	
	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() {
	if (name) delete[] name;
}

void Photon_Cannon::show_status() {
	std::cout << "Photon_Cannon : " << name << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " )" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2(pc1); // 복사가 이루어진다.
	Photon_Cannon pc3 = pc2; // 복사가 이루어진다.
	
	pc1.show_status();
	pc2.show_status();
	pc3.show_status();
}