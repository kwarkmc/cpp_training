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
	virtual string GetContent() const {
		return "";
	}
	
private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {
		this->text = text;
	} 
	
	string GetText() const { return text; }
	string GetContent() const { return text; }
	
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
	string GetContent() const { return (string)*image; }
	
private:
	Image *image; //Image라는 클래스 자체가 ImageMessage 클래스 내로 들어가게 되면, ImageMessage 클래스가 아주 무거워지기 때문에, 포인터로 조작한다.
};

void printMessage(Message *m) { //부모 포인터에 가상 함수가 있기 때문에 그 가상 함수를 오버로딩 해서 사용하면 한개의 함수로 Message 클래스에서 상속된 두 개의 메시지를 모두 받을 수 있다.
	cout << "보낸 시간 : " << m->GetSendTime() << endl;
	cout << "보낸 사람 : " << m->GetSendName() << endl;
	cout << "보낸 내용 : " << m->GetContent() << endl;
	cout << endl;
}

/*void printMessage(ImageMessage *m) {
	cout << "보낸 시간 : " << m->GetSendTime() << endl;
	cout << "보낸 사람 : " << m->GetSendName() << endl;
	cout << "보낸 내용 : " << (string)*m->GetImage() << endl;
	cout << endl;
}
*/
int main() {
	// 두들 : "안녕"
	// 두들 : "강아지 사진"
	
	Image *p_dogImage = new Image();
	
	Message *messages[] = {
		new TextMessage(10, "두들", "안녕"),
		new TextMessage(11, "두들", "안녕"),
		new TextMessage(12, "두들", "안녕"),
		new ImageMessage(20, "두들", p_dogImage),
	}; //메시지를 가르키는 포인터의 배열을 만든다.
	
	
	for (Message *m : messages) {
		printMessage(m);
	}
	/*
	for (int i = 0; i < 4; i++) {
		printMessage(*messages[i]);
	}
	*/
	
	/*
	TextMessage *hello = new TextMessage(10, "두들", "안녕");
	ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);
	*/
	
	delete p_dogImage;
}