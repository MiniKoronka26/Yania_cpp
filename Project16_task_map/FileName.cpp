#include <iostream>
#include <map>
#include <string>
#include <windows.h>
using namespace std;



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	map<string, string> dict = {
		{"��", "�at"},
		{"������", "dog"},
		{"������", "apple"},
		{"�����", "school"},
		{"������", "car"}
	};

	cout << dict["��"];

	dict.insert("������", "tree");

	cout << dict.begin();//problem
	





	return 0;
}