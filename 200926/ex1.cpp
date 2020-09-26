// 클래스 = 자료 저장 + 자료 처리 = 변수 + 함수
// 클래스(타입) : 특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀 (자료 형)
// 객체(오브젝트) : 그 틀을 이용하여 찍어낸 객체 (변수, 메모리 상의 공간)


#include <iostream>

using namespace std;

struct TV {
	bool powerOn;
	int channel;
	int volume;
};

int main() {
	TV lg;
	lg.powerOn = true;
	lg.channel = 10;
	lg.volume = 50;
}