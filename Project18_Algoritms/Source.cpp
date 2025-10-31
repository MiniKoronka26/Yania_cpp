#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

class employee {
    string name;
    double salary;
public:
    employee(string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    void print() const {
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
    }


    double get_salary() const {
        return salary;
    }

    string get_name() const {
        return name;
    }


};



int main() {

    //find 
    //find_if

    //vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };

    /*auto res = find(v.begin(), v.end(), 3);


    if (res != v.end()) {
        cout << "Found!\n" << *res;
    }
    else {
        cout << "Not found";
    }*/

    /*auto res = find_if(v.begin(), v.end(), [](int a) {
        return a < 0;
        });

    if (res != v.end()) {
        cout << "Found!\n" << *res;
    }
    else {
        cout << "Not found";
    }*/

    //

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };

    char s = 'D';

    auto res = find_if(employees.begin(), employees.end(), [s](const employee& e) {
        return e. get_name()[0] == s;
        });

    res->print();*/

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("AEve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("AJack Taylor", 80000.10)
    };*/

    // copy_if

    /*vector<employee> result;

    copy_if(employees.begin(),
        employees.end(),
        back_inserter(result)
        , [](const employee& e) {
            return e.get_name()[0] == 'A';
        });

    for (employee e : result) {
        e.print();
    }*/

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };

    vector<int> result;

    copy_if(v.begin(),
        v.end(),
        back_inserter(result)
        , [](const int& a) {
            return a % 2 == 0;
        });

    for (int e : result) {
        cout << e << " ";
    }*/

    //remove, remove_if

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3, 3, 22, 97, 33, 11, 100, 3, -2 };

    auto it = remove(v.begin(), v.end(), 3);

    v.erase(it, v.end());

    for (int el : v) {
            cout << el << " ";
        }*/

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3, 3, 22, 97, 33, 11, 100, 3, -2 };

    auto it = remove_if(v.begin(), v.end(), [](int a) {
        return a < 0;
        });

    v.erase(it, v.end());

    for (int el : v) {
        cout << el << " ";
    }*/

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("AEve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("AJack Taylor", 80000.10)
    };

    auto it = remove_if(employees.begin(), employees.end(), [](const employee& e) {
        return e.get_salary() > 80000;
        });

    employees.erase(it, employees.end());

    for (employee el : employees) {
        el.print();
    }*/

    // max_element, min_element, minmax_element
    
    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };
    
    auto it = min_element(v.begin(), v.end());

    cout << *it;*/

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };

    auto res = minmax_element(employees.begin(), employees.end(), [](const employee& e1, const employee& e2) {
        return e1.get_salary() < e2.get_salary();
    });

    res.first->print();//min
    res.second->print();//max*/

    //accumulate

    //vector<int> v = { 10, 1, -6, 4, 2, 7, 1, 4, 8 };

    //int res = accumulate(v.begin(), v.end(), 0, [](int prev, int current) {
    //    return current % 2 == 0 ? prev + current : prev;// ':' â³ää³ëÿº if â³ä else
    //    });

    //cout << res;

    vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };

    double res = accumulate(employees.begin(), employees.end(), (double)0, [](double prev, const employee& e) {
        return prev + e.get_salary();
        });

    cout << fixed << setprecision(2) << res;





    return 0;
}