// 클래스 간에 공통적인 인자가 있는지, 있다면 합쳐주는것이 객체지향 프로그래밍.

// 메시지
// 텍스트
// 이미지

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() {
		return "사진";
	}
};

class Message {
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime;
		this->sendName = sendName;
	}
	
	int GetSendTime() const {return sendTime;}
	string GetSendName() const {return sendName;}
private:
	int sendTime;
	string sendName;
}

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {
		this->text = text;
	} 
	
	string GetText() const {return text;}
	
private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image) 
		: Message (sendTime, sendName) {
		this->image = image; //포인터 자체를 얕은 복사하는 것은 문제가 되지 않는다.
	} 
	Image *GetImage() const {return image;}
private:
	Image *image; //Image라는 클래스 자체가 ImageMessage 클래스 내로 들어가게 되면, ImageMessage 클래스가 아주 무거워지기 때문에, 포인터로 조작한다.
};

int main() {
	// 두들 : "안녕"
	// 두들 : "강아지 사진"
	
	Image *p_dogImage = new Image();
	TextMessage *hello = new TextMessage(10, "두들", "안녕");
	ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);
	
	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
	cout << "보낸 시람 : " << hello->GetSendName() << endl;
	cout << "보낸 내용 : " << hello->GetText() << endl;
	cout << endl;
	
	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
	cout << "보낸 시람 : " << dog->GetSendName() << endl;
	cout << "보낸 내용 : " << (string)*dog->GetImage() << endl;
	cout << endl;
	
	delete hello;
	delete dog;
	delete p_dogImage;
}