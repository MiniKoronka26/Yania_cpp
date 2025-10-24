#include <iostream>
#include <map>
#include <string>
#include <windows.h>
using namespace std;



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	map<string, string> dict = {
		{"кіт", "сat"},
		{"Собака", "dog"},
		{"Яблуко", "apple"},
		{"Школа", "school"},
		{"Машина", "car"}
	};

	cout << dict["кіт"];

	dict.insert("дерево", "tree");

	cout << dict.begin();//problem
	





	return 0;
}