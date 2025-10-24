#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void func1() {
    cout << "func1()";
}

void func2() {
    cout << "func2()";
}

void print_vector(vector<int> v, function<bool(int)> fn) { // callback
    for (int el : v) {
        if(fn(el))
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

bool is_plus(int a) {
    return a > 0;
}

bool is_s1mple(int a) {
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++)
        if (a % i == 0) return false;
    return true;
}

int main() {

    /*function<void()> p;

    p = func1;
    func1();
    p();

    p = func2;
    p();*/

    vector<int> v = { 10, 1, 6, -2, 3, 3, 22, 33, 11, 100, -2, 97 };
 
    print_vector(v, is_even);
    print_vector(v, is_odd);
    print_vector(v, is_plus);
    print_vector(v, is_s1mple);




    return 0;
}