#include <iostream>
#include <string.h>

class string {
private:
	char *str;
	int len;
public:
	string(char c, int n);
	string(const char *s);
	string(const string &s);
	~string();
	
	void add_string(const string &s);
	void copy_string(const string &s);
	int strlen();
}

string::string(char c, int n) {
	str = new char[n+1];
	for (int i = 0; i < n; i++) {
		str[i] = c;
	}
	str[n] = 0;
	len = n;
}

string::string(const char *s) {
	str = new char[strlen(s) + 1];
	strcpy(str, s);
	len = strlen(s);
}

string::string(const string &s)
	
	//work_on
	
	4-3