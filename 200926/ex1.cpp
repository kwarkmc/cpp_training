// 클래스 = 자료 저장 + 자료 처리 = 변수 + 함수
// 클래스(타입) : 특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀 (자료 형)
// 객체(오브젝트) : 그 틀을 이용하여 찍어낸 객체 (변수, 메모리 상의 공간)

//1. volume 변수를 setVolume 함수 안에서만 변경 가능하고, 밖에서는 불가능하게 만들고 싶다. -> 접근 지시자 이용 (캡슐화)

#include <iostream>

using namespace std;

//private, protected, public

class TV {
private: // struct 에서는 private 가 없으면 자동으로 public이 된다. / class 에서는 자동으로 private 가 된다.
	bool powerOn;
	int channel;
	int volume;
	
public:
	void on() {
		powerOn = true;
		cout << "TV를 켰습니다." << endl;
	}
	
	void off() {
		powerOn = false;
		cout << "TV를 껐습니다." << endl;
	}
	
	void setChannel(int cnl) {
		if (cnl >= 1 && cnl <= 999) {
			channel = cnl;
			cout << "채널을 " << cnl << "(으)로 바꿉니다." << endl;
		}
	}
	
	void setVolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "볼륨을 " << vol << "(으)로 바꿉니다." << endl;
		}
	}
};

int main() {
	TV lg;
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);
	lg.setChannel(-73);
}