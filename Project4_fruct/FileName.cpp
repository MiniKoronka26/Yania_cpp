#include <iostream>
using namespace std;
#define RECT_SIZE 4


class fraction {
	int numerator, denominator;
public:

	fraction() {
		numerator = 0;
		denominator = 1;
	}

	fraction(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void set(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void set() {
		cout << "Enter numerator: ";
		cin >> numerator;
		cout << "Enter denominator: ";
		cin >> denominator;

	}

	void set_num(int numerator) {
		this->numerator = numerator;
	}

	void set_den(int denominator) {
		this->denominator = denominator;
	}

	void reduce(int& numerator, int& denomirator) {
		int max = 1;
		for (int i = 1; i < this->denominator; i++) {
			if (this->denominator % i == 0 && this->numerator % i == 0) {
				max = i;
			}
		}
		set_num(this->numerator / max);
		set_den(this->denominator / max);
	}

	void whole_part() {
		if (numerator > denominator) {
			cout << " = \n" << double(numerator) / denominator << " \n";
		}
	}

	int get_numerator() const {
		return numerator;
	}
	int get_denominator() const {
		return denominator;
	}

	int get_integer() const {
		return numerator / denominator;
	}

	double get_double() {
		return double(numerator) / denominator;
	}

	/*fraction add(fraction other) {
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
	}*/

	operator int() {
		return get_integer();
	}

	operator double() {
		return get_double();
	}

	void print() {
		cout << numerator << "/" << denominator << "\n";
	}
};

fraction operator+(const fraction& first, const fraction& second) {
	int res_denominator = first.get_denominator() * second.get_denominator();
	int res_numerator =
		first.get_numerator() * second.get_denominator() + first.get_denominator() * second.get_numerator();

	fraction res(res_numerator, res_denominator);
	res.reduce(res_numerator, res_denominator);
	return res;
}

fraction operator-(const fraction& first, const fraction& second) {
	int res_denominator = first.get_denominator() * second.get_denominator();
	int res_numerator =
		first.get_numerator() * second.get_denominator() - first.get_denominator() * second.get_numerator();

	fraction res(res_numerator, res_denominator);
	res.reduce(res_numerator, res_denominator);
	return res;
}

fraction operator*(const fraction& first, const fraction& second) {
	int res_denominator = first.get_denominator() * second.get_denominator();
	int res_numerator = first.get_numerator() * second.get_numerator();

	fraction res(res_numerator, res_denominator);
	res.reduce(res_numerator, res_denominator);

	return res;
}

fraction operator/(const fraction& first, const fraction& second) {
	int res_denominator = first.get_denominator() * second.get_numerator();
	int res_numerator = first.get_numerator() * second.get_denominator();

	fraction res(res_numerator, res_denominator);
	res.reduce(res_numerator, res_denominator);

	return res;
}

fraction operator+(const fraction& first, int number) {
	return first + fraction(number, 1);
}

fraction operator+(int number, const fraction& first) {
	return first + fraction(number, 1);
}

fraction operator-(const fraction& first, int number) {
	return first - fraction(number, 1);
}

fraction operator-(int number, const fraction& first) {
	return fraction(number, 1) - first;
}

fraction operator*(const fraction& first, int number) {
	return first * fraction(number, 1);
}

fraction operator*(int number, const fraction& first) {
	return fraction(number, 1) * first;
}

fraction operator/(const fraction& first, int number) {
	return first / fraction(number, 1);
}

fraction operator/(int number, const fraction& first) {
	return fraction(number, 1) / first;
}

ostream& operator << (ostream& os, const fraction& obj) {
	os << obj.get_numerator() << "/" << obj.get_denominator() << "\n";
	return os;
}

istream& operator >> (istream& is, fraction& obj) {
	int n;
	int d;
	cout << "Enter numerator: ";
	is >> n;
	cout << "\nEnter denominator: ";
	is >> d;
	obj.set(n, d);
	return is;
}


int main() {


	/*fraction f1;
	f1.set(2, 3);

	fraction f2;
	f2.set(3, 4);

	fraction f1(3, 4), f2(1, 2);
	fraction f3 = f1 + f2;
	f3.print();*/

	fraction f1;

	int num = 2;

	cin >> f1;
	cout << f1;

	cout << " + \n " << num << "\n = \n" << f1 + num
		<< "----------\n"
		<< f1 << " - \n " << num << "\n = \n" << f1 - num
		<< "----------\n"
		<< f1 << " * \n " << num << "\n = \n" << f1 * num
		<< "----------\n"
		<< f1 << " / \n " << num << "\n = \n" << f1 / num;

	cout << "----------\n" << "----------\n "
		<< num << "\n + \n" << f1 << " = \n" << num + f1
		<< "----------\n "
		<< num << "\n - \n" << f1 << " = \n" << num - f1
		<< "----------\n "
		<< num << "\n * \n" << f1 << " = \n" << num * f1
		<< "----------\n "
		<< num << "\n / \n" << f1 << " = \n" << num / f1;

	return 0;
}