#include <iostream>
using namespace std;

class my_string {
	char* str;
	int length;

	void copy_str(const char* str) {
		this->length = strlen(str);
		this->str = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[this->length] = '\0';
	}

public:													
	my_string() {
		this->str = nullptr;
		this->length = 0;
	}

	my_string(const char* str) {
		copy_str(str);
	}

	my_string(const my_string& other) {
		copy_str(other.str);
	}


	int get_length() const {
		return length;
	}

	void set() {
		cin >> str;
	}

	void print() const {
		cout << str;
	}

	~my_string() {
		delete[] str;
	}

};

int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	my_string s1("hello world");
	s1.print();

	cout << "\n";
	
	my_string s2 = s1;
	s2.print();

	return 0;
}

