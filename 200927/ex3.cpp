//static : 정적 <-> 동적

#include <iostream>

using namespace std;

//0~1 float R G B

class Color {
public:
	Color() : r(0), g(0), b(0) {}
	Color(float r, float g, float b) : r(r), g(g), b(b) {}
	
	float GetR() {
		return r;
	}
	float GetG() {
		return g;
	}
	float GetB() {
		return b;
	}
	
	static Color MixColors(Color a, Color b) {
		Color res((a.r + b.r)/2, (a.g + b.g)/2, (a.b + b.b)/2); //res를 main 함수에서 static 한 멤버로서 Color 클래스 안으로 가져왔기 때문에 private space 안에 있는 r, g, b 값을 사용 가능하다. Color 클래스 외부에서는 Get 함수를 따로 선언하여 사용하여야 했다.
		return res;
	/*
	return Color ((a.GetR() + b.GetR())/2, (a.GetG() + b.GetG())/2, (a.GetB() + b.GetB())/2);
	*/
	}
private:
	float r;
	float g;
	float b;
};


	
	

int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);
	
	Color purple = Color::MixColors(blue, red);
	
	cout << "r : " << purple.GetR() << " g = " << purple.GetG() << " b = " << purple.GetB() << endl;
}