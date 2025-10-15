#include <iostream>
#include <string>
#define SIZE 10

using namespace std;

// Наслідування - це механізм, прри якому об'єкти одного класу
// отримують властивості об'єкта іншого класу,
// і добввляються властивості, які характерні тільки йому.

// Наслідування - це розширення одного класу іншим класом.

// Людина(прізвище, імя, вік) (базовий, батьківський, супер)
// Працівник(зар.плата, посада) (похідний, дочірній, сабкласи)

class person {
protected:
	string name, surname;
	int age;
public:

	person() {
		name = "no set name";
		surname = "no set surname";
		age = 0;
	}

	person(string name, string surname, int age) {
		this->name = name;
		this->surname = surname;
		this->age = age;
	}

	void set_name(string name) {
		this->name = name;
	}

	string get_name() const {
		return name;
	}

	void set_surname(string surname) {
		this->surname = surname;
	}

	string get_surname() const {
		return surname;
	}

	void set_age(int age) {
		this->age = age;
	}

	int get_age() const {
		return age;
	}


	void eat() {
		cout << "Eat!";
	}

	void print() const {
		cout << "name: " << name << "\n"
			<< "surname: " << surname << "\n"
			<< "age: " << age << "\n";
	}
};

class employee : public person {
	int salary;
public:

	employee()
		: person() {
		salary = 0;
	}

	employee(string name, string surname, int age, int salary)
		: person(name, surname, age) {
		this->salary = salary;
	}

	void set_salary(int salary) {
		this->salary = salary;
	}

	int get_salary() const {
		return salary;
	}

	void print() const {
		person::print();
		cout << "surname: " << surname << "\n";
		cout << "salary: " << salary << "\n";
	}
}; 

class nurse : public employee {
	string hospital;
public:

	nurse() : employee() {
		hospital = "not set hospital";
	}

	nurse(string name, string surname, string hospital, int age, int salary) 
		: employee(name, surname, age, salary) {
		this->hospital = hospital;
	}

	void print() const {
		employee::print();
		cout << "hospital: " << hospital << "\n";
	}

};

class student : public person {
	string class_name;
	int marks[SIZE];
public:

	student()
		: person() {
		class_name = "no set class_name";
	}

	student(string name, string surname, int age, string class_name, int marks[SIZE])
		: person(name, surname, age) {
		this->class_name = class_name;
		for (int i = 0; i < SIZE; i++) {
			this->marks[i] = marks[i];
		}
	}

	void set_class_name(string class_name) {
		this->class_name = class_name;
	}

	string get_class_name() const {
		return class_name;
	}

	float avarage() {
		float sum = 0;
		for (int i = 0; i < SIZE; i++) {
			sum += marks[i];
		}
		return sum / SIZE;
	}

	void print() const {
		person::print();
		cout << "class_name: " << class_name << "\n";
	}
};

class aspirant : public student {
	string diploma;
	int d_mark;
public:
	aspirant() : student(){
		diploma = "no set diploma";
		d_mark = 0;
	}

	aspirant(string name, string surname, int age, string class_name, int marks[SIZE], string diploma, int d_mark)
		: student(name, surname, age, class_name, marks) {
		this->diploma = diploma;
		this->d_mark = d_mark;
	}

	bool get_d(int a) {
		if (avarage() + d_mark >= a)
			return true;
		return false;
	}

};

class poet : public person {
	string popular_book;
public:

	poet()
		: person() {
		popular_book = "popular_book";
	}

	poet(string name, string surname, int age, string class_name)
		: person(name, surname, age) {
		this->popular_book = popular_book;
	}

	
	void set_popular_book(string popular_book) {
		this->popular_book = popular_book;
	}

	string get_popular_book() const {
		return popular_book;
	}

	void print() const {
		person::print();
		cout << "popular_book: " << popular_book << "\n";
	}
};


int main() {

	//employee e("John", "Smow", 30, 3000);
	//*e.set_name("John");
	//e.set_surname("Smow");
	//e.set_age(30);
	//e.set_salary(3000);*/
	//e.print();

	//e.eat();

	//student s("Jack", "king", 20, "MV34");
	//*s.set_name("Jack"); 
	//s.set_surname("king");
	//s.set_age(20);
	//s.set_class_name("MV34");*/
	//s.print();


	//poet p("Holly", "Jackson", 20, "'a good girl quid to murder'");
	//*p.set_name("Holly");
	//p.set_surname("Jackson");
	//p.set_age(20);
	//p.set_popular_book("'a good girl quid to murder'");*/
	//p.print();

	/*nurse n("Alla", "Manson", "A1", 23, 5000);
	n.print();*/
	
	int marks[SIZE] = { 11,12,10,9,8,10,6,7,8,9 };

	aspirant a("Yana", "Mazepa", 14, "p45", marks ,"smth", 15);
	cout << a.get_d(18);


	return 0;
}