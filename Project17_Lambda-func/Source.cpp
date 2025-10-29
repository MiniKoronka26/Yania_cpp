#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;


void print_vector(vector<int> v, function<bool(int)> fn) {
    for (int el : v) {
        if (fn(el))
            cout << el << " ";
    }
    cout << "\n";
}

bool is_even(int a) {
    return a % 2 == 0;
}

bool is_odd(int a) {
    return a % 2 != 0;
}

bool is_simple(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_negative(int a) {
    return a < 0;
}

int amout(vector<int> v, function<bool(int)> fn) {
    int count = 0;
    for (int el : v) {
        if (fn(el))
            count++;
    }
    return count;
}

bool two_num(int a) {
    if (a < 0) 
        a *= -1;
    if (a > 9 && a < 100) return true;
    return false;
}

int getLenght(int a) {
    int count = 0;
    while (a) {
        a /= 10;
        count++;
    }
    return count;
}

class employee {
    string name;
    double salary;
public:
    employee(string name, int salary) {
        this->name = name; 
        this->salary = salary;
    }

    void print() const {
        cout << "name: " << name << "\n"
            << "nalary: " << salary << "\n";
    }

    double get_salary() const {
        return salary;
    }
    
    string get_name() const {
        return name;
    }

    char f_name() const {
        return name[0];
    }
};

bool operator<(const employee& first, const employee& second) {
    return first.get_name() < second.get_name();
}

class student {
    string name, surname, curse;
    double average;
public:
    student(string name, string surname, string curse, double average) {
        this->name = name;
        this->surname = surname; 
        this->curse = curse;
        this->average = average;
    }

    void print() const {
        cout << "name: " << name << "\n"
            << "surname: " << surname << "\n"
            << "curse: " << curse << "\n"
            << "average: " << average << "\n";
    }

    double get_average() const {
        return average;
    }

    string get_curse() const {
        return curse;
    }
};

void my_sort(vector<int>& v, function<bool(int, int)> fn) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = v.size() - 1; j > i; j--) {
            if (fn(v[j], v[j - 1]))
                swap(v[j], v[j - 1]);
        }
    }
}

int main() {

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -22, 97, 33, 11, 100, -2 };
    print_vector(v, [](int a) {
        return a % 2 == 0;
    });
    print_vector(v, [](int a) {
        return a % 2 != 0;
    });
    print_vector(v, [](int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
        });
    print_vector(v, [](int a) {
        return a < 0; });*/

    // Àíî³ìí³(ëÿìäà ôóíêö³¿)
    // [](){}  

    /*function<void(int)> f = [](int a) {
        cout << "Value: " << a;
    };

    f(100);*/

    /*[](int a) {
        cout << "Value: " << a;
    }(100);*/

    /*vector<int> v = {10, 1, 6, -2, 3, 23, 3, -22, 97, 33, 11, 100, -2};
    cout << amout(v, [](int a) {
        return a % 2 == 0;
        }) << "\n";
    cout << amout(v, [](int a) {
        return a > 0;
        }) << "\n";
    //cout << amout(v, [](int a) {
    //    return two_num(a);
    //    }) << "\n";
    int num;
    cin >> num;
    cout << amout(v, [&num](int a) {
        num = 100;
        return getLenght(a) == num;
        }) << "\n";*/

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -22, 97, 33, 11, 100, -2 };

    int count = count_if(v.begin(), v.end(), [](int a) 
        {
        return a % 2 != 0;
        });
    cout << count;*/

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Grace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };*/

    /*cout << count_if(employees.begin(), employees.end(), [](const employee& e) {
        return e.get_salary() > 60000;
        }) << "\n";
    cout << count_if(employees.begin(), employees.end(), [](const employee& e) {
        return e.f_name() == 'A';
        }) << "\n";*/

    /*for_each(employees.begin(),
        employees.end(),
        [](const employee& e) {
            e.print();
        }
    );*/

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -22, 97, 33, 11, 100, -2 };

    int sum = 0;

    for_each(v.begin(), v.end(), [&sum](int el) {
        sum += el;
        });
    cout << sum;*/

    /*vector<student> v = {
        student("Yana", "Mazepa", "IT", 10),
        student("Mykola", "Lysenko", "Musicology", 8.8),
        student("Lesia", "Ukrainka", "IT", 9.9),
        student("Ivan", "Franko", "Geography", 8.5),
        student("Bohdan", "Khmelnytskyi", "IT", 5.1),
        student("Maria", "Zankovetska", "Theater Arts", 9.4),
        student("Volodymyr", "Vernadsky", "Geology", 7.9),
        student("Hryhorii", "Skovoroda", "IT", 3.7),
        student("Olha", "Kobylianska", "Linguistics", 8.9),
    };

    cout << count_if(v.begin(), v.end(), [](const student s){
        return s.get_average() > 9 && s.get_curse() == "IT";
        });

    cout << "\n";

    for_each(v.begin(), v.end(), [](student s) {
        s.print();
        });*/

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -22, 97, 33, 11, 100, -2 };

    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
        });

    function<bool(int, int)> fn = [](int a, int b) {
        return a > b;
        };

    my_sort(v, fn);

    for (int el : v)
        cout << el << " ";*/

    vector<employee> employees = {
        employee("Eve Adams", 65000.00),
        employee("Jack Taylor", 80000.10),
        employee("Henry Ford", 55000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Ivy Green", 68000.00),
        employee("Bob Johnson", 75000.50),
        employee("Frank White", 72000.75),
        employee("Alice Smith", 60000.00),
        employee("Grace Kelly", 88000.00)
    };

    /*sort(employees.begin(), employees.end(), [](employee e1, employee e2) {
        return e1.get_salary() > e2.get_salary();
        });
     
    for_each(employees.begin(),
            employees.end(),
            [](const employee& e) {
                cout << e.get_salary() << "\n";
            }
        );*/

    /*sort(employees.begin(), employees.end(), [](employee e1, employee e2) {
        return e1.get_name() > e2.get_name();
        });

    for_each(employees.begin(),
        employees.end(),
        [](const employee& e) {
            e.print();
        }
    );*/

    sort(employees.begin(), employees.end());

    for_each(employees.begin(),
        employees.end(),
        [](const employee& e) {
            e.print();
        }
    );

    return 0;
}