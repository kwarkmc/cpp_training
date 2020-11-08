#include <iostream>
#include <string.h>

class MyString {
private:
	char* string_content; //문자열 데이터를 가르키는 포인터
	int string_length; // 문자열의 길이
	
	int memory_capacity;
	
public:
	MyString(char c);
	//문자 하나로 생성
	MyString(const char* str); // 내부 변수의 값을 바꾸지 않는다면, 함수를 꼭 상수로 정의해야 한다!!
	//문자열로 생성
	MyString(const MyString& str);
	//복사 생성자
	~MyString();
	
	void print() const;
	void println() const;
	
	int length() const;
	int capacity() const;
	void reserve(int size);
	
	//assign 함수
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
};

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];
	
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const {
	return string_length;
}

void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	if(str.string_length > memory_capacity) {
		//할당을 다시 해주어야 한다. 원래 할당되었던 배열의 크기보다 크기 때문에.
		delete[] string_content;
		
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	
	string_length = str.string_length;
	
	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length < memory_capacity) {
		delete[] string_content;
		
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	
	string_length = str_length;
	
	return *this;
}

int MyString::capacity() const {
	return memory_capacity;
}

void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char *prev_string_content = string_content;
		
		string_content = new char[size];
		memory_capacity = size;
		
		for (int i = 0; i != string_length; i++) {
			string_content[i] = prev_string_content[i];
		}
		
		delete[] prev_string_content;
	}
}

int main() {
	MyString str1("very very very long string");
	str1.reserve(30);
	
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	
	str1.println();
}

//4-5