#include <iostream>
#include <cmath>
using namespace std;

template<class T>
class s {
    static int count;
public:


    static T s_triangle(T a, T h) {
        count++;
        return 0, 5 * h * a;
    }
    static T s_triangle(T a, T b, T c) {
        count++;

        T p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    static T s_rectangle(T a, T b) {
        count++;
        return a * b;
    }

    static T s_square(T a) {
        count++;
        return a * a;
    }

    static T s_diamond(T d1, T d2) {
        count++;
        return 0, 5 * d1 * d2;
    }

    static int get_count() {
        return count;
    }

};

template<class T>
int s<T>::count = 0;

int main() {


    cout << "Triangle 1: " << s<double>::s_triangle(3.8, 4.5)
        << " || Triangle 2: " << s<double>::s_triangle(3, 4, 5)
        << " || Rectangle: " << s<double>::s_rectangle(3, 4)
        << " || Square: " << s<double>::s_square(3)
        << " || Diamond: " << s<double>::s_diamond(3, 4);

    cout << "\nCount: " << s<double>::get_count();










    return 0;
}