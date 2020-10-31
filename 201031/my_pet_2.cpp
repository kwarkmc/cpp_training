#include <iostream>

class Animal {
	private:
		int food; //멤버 변수 (member variable)
		int weight;
	public:
		void set_animal(int _food, int _weight) { //멤버 함수 (member function)
			food = _food;
			weight = _weight;
		}
		void increase_food(int inc) {
			food += food;
			weight += (inc / 3);
		}
		void view_stat() {
			std::cout << "이 동물의 food	:" << food << std::endl;
			std::cout << "이 동물의 weight	:" << weight << std::endl;
		}
};

int main() {
	Animal animal;
	//animal.food = 100; private space 안에 있는 food 변수에는 직접 접근할 수 없다.
	animal.set_animal(100, 50);
	animal.increase_food(30);
	animal.view_stat();
}

//4-1