#include <iostream>
using namespace std;

//Шаблонні класи

template<class T>
//class my_class {
//    T a;
//public:
//
//    my_class() { a = 0; }
//    my_class(T a) { this->a = a; }
//    void set_a(T a) { this->a = a; }
//    T get_a() const { return a; }
//    void print() const { cout << a << "\n"; }
//    friend void func(my_class<T> obj1);
//};
class dot {
    T x, y, z;
public:
    dot(T x,T y, T z) { 
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    template<class T>
    friend double dot_v(dot<T> a, dot<T> b);
};

//void func(my_class<int> obj1) {
//
//    cout << obj1.a;
//
//}

//AB = √(xb - xa)2 + (yb - ya)2 + (zb - za)2
template<class T>
double dot_v(dot<T> a, dot<T> b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));


    
}



int main() {

    /*my_class<int> obj1(100);   
    obj1.print();

    my_class<double> obj2(123.22);
    obj2.print();

    my_class<char> obj3('a');
    obj3.print();

    my_class<string> obj4("smth");
    obj4.print();*/

    /*my_class<int> obj(4);
    func(obj);*/

    dot<int> obj1(1, 2, 3);
    dot<int> obj2(6, 7, 8);
    cout << dot_v(obj1, obj2);
    



    return 0;
}