#include <iostream>
using namespace std;
#define RECT_SIZE 4

//Об'єкно орієнтоване рограмуванння(ООП) - це вид програмування,
//в яком упрограма реалізується у вигяді об'єктів, 
//що взаємодіють між собою

//ООП  реалізується на основі 3 базових прринципів:
//- Інкапсуляція - це об'єднання даних та матодів роботи з цими данними
//в одне ціле - об'єкт.Основа властивість інкапсуляції - приховування даних.
//- Наслідування
//- Поліморфізм

//Клас - це спеціальна конструкція, яка використовуються для групування 
//пов'язаних між собою даних да фуекції. Дані називаються поля, а функції 
//- методами

//1 Фуекціональне програмуавння(C)
//struct point {
//	int x;
//	int y;
//};
//
//void set_point(point& p) {
//	cout << "Enter x: ";
//	cin >> p.x;
//	cout << "Enter y: ";
//	cin >> p.y;
//}
//
//void print_point(point p) {
//	cout << "x: " << p.x << ", y: " << p.y << "\n";
//
//}

//ООП
class point {
private:
	// дані, поля
	int x, y;

	//фунцкії, методи
public:

	void set() {
		cout << "Enter x:";
		cin >> x;
		cout << "Enter y:";
		cin >> y;
	}

	void set(int x_value, int y_value) {
		x = x_value;
		y = y_value;
	}


	//методи Аксесори
	void set_x(int x_value) {
		x = x_value;
	}

	void set_y(int y_value) {
		y = y_value;
	}

	//методи Інспектори                                     
	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	void print() {
		cout << "x: " << x << ", y: " << y << "\n";
	}
};

class rectangle {

	point points[4];

public:

	void set() {
		for (int i = 0; i < RECT_SIZE; i++)
		{
			points[i].set();
		}
	}
	void print()
	{
		for (int i = 0; i < RECT_SIZE; i++)
		{
			points[i].print();
		}
	}
};

class person {

	char name[100];
	float height;
public:

	void set(const char* name_value, float height_value) {

		strcpy_s(name, name_value);
		height = height_value;
	}

	void print() {
		cout << "name: " << name << " | height: " << height << "\n";
	}

};

class student {
private:
	char surname[100];
	int age;

public:

	void set() {
		cout << "Enter surname:";
		gets_s(surname);
		cout << "Enter age:";
		cin >> age;
	}

	void set(const char* surname_value, int age_value) {
		
		strcpy_s(surname, surname_value);
		age = age_value;
	}


	void set_surname(const char* surname_value) {
		strcpy_s(surname, surname_value);
	}

	void set_age(int age_value) {
		age = age_value;
	}

	char* get_surname() {
		return surname;
	}

	int get_age() {
		return age;
	}

	void print() {
		cout << "surname: " << surname << " | age: " << age << "\n";
	}
};

class fraction {
	int numerator, denominator;
public:
	void set(int n, int d) {
		numerator = n;
		denominator = d;
	}

	void set() {
		cout << "Enter numerator: ";
		cin >> numerator;
		cout << "Enter denominator: ";
		cin >> denominator;

	}

	int get_integer() {
		return numerator / denominator;
	}

	double get_double() {
		return double(numerator) / denominator;
	}

	fraction add(fraction other) {
		int res_denominator = this->denominator * other.denominator;
		int res_numerator = 
			this->numerator * other.denominator + this->denominator * other.numerator;

		fraction res;
		res.set(res_numerator, res_denominator);

		return res;
	}

	fraction minus(fraction other) {
		int res_denominator = this->denominator * other.denominator;
		int res_numerator =
			this->numerator * other.denominator - this->denominator * other.numerator;

		fraction res;
		res.set(res_numerator, res_denominator);

		return res;
	}

	fraction mult(fraction other) {
		int res_denominator = this->denominator * other.denominator;
		int res_numerator = this->numerator * other.numerator;

		fraction res;
		res.set(res_numerator, res_denominator);

		return res;
	}

	fraction del(fraction other) {
		int res_numerator = this->numerator * other.denominator; 
		int res_denominator = this->denominator * other.numerator;

		fraction res;
		res.set(res_numerator, res_denominator);

		return res;
	}



	void print() {
		cout << numerator << "/" << denominator << "\n";
	}
};

int main() {
	/*point p1;

	set_point(p1);
	print_point(p1);*/

	//C++
	/*point p1;
	p1.set();
	p1.print();

	point p2;
	p2.set();
	p2.print();

	point p3;
	p3.set(100, 200);
	p3.print();
	p3.set_x(1000);
	p3.print();
	p3.set_y(2000);
	p3.print();*/
	
	/*point p4;
	p4.set(10, 20);
	
	cout << p4.get_x();*/

	/*person p1;
	p1.set("yana", 163);
	p1.print();*/

	/*student p1;
	p1.set();
	p1.print();

	p1.set("mazepa", 14);
	p1.print();

	p1.set_surname("fedak");
	p1.print();

	p1.set_age(15);
	p1.print();

	cout << p1.get_surname() << " , " << p1.get_age() << "\n";*/

	/*rectangle r;
	r.set();
	r.print();*/

	/*fraction f1;
	f1.set(5, 4);
	f1.print();
	cout << f1.get_integer() << "\n" << f1.get_double();*/

	fraction f1;
	f1.set(2, 3);

	fraction f2;
	f2.set(3, 4);

	fraction f3 = f1.add(f2);
	f3.print();
	f3.get_double();

	fraction f4 = f1.minus(f2);
	f4.print();
	f4.get_double();

	fraction f5 = f1.mult(f2);
	f5.print();
	f5.get_double();

	fraction f6 = f1.del(f2);
	f6.print();
	f6.get_double();


	return 0;
}