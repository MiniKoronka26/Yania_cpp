#include <iostream>
#include <string>
#define PI 3.14
using namespace std;

//Множинне наслідування це наявність в похідного класу більше ніж одного базового.

class car {
    string wheels;
public:
    car(string wheels) {
        this->wheels = wheels;
    }

    void drive() {
        cout << "I am driving!\n";
    }

    string get_wheels() const {
        return wheels;
    }
};

class airplane {
    string wings;
public:
    airplane(string wings) {
        this->wings = wings;
    }

    void fly() {
        cout << "I am fly!";
    }

    string get_wings() const{
        return wings;
    }
};

class flying_car : public car, public airplane {

public:
    flying_car(string wheels, string wings): car(wheels), airplane(wings) {
        //...
    }

};

//1

class circle {
    int radius;
public:
    circle() {
        radius = 0;
    }
    circle(int radius) {
        this->radius = radius;
    }

    void set() {
        cout << "\nenter radius: ";
        cin >> radius;
    }

    int get() const {
        return radius;
    }

    double perimetr_circle() {
        return 2 * PI * radius;
    }
    
    double area_circle() {
        return PI * radius * radius;
    }
};

class square {
    int side;
public:
    square() {
        side = 0;
    }
    square(int side) {
        this->side = side;
    }

    void set() {
        cout << "\nenter side: ";
        cin >> side;
    }

    int get() const {
        return side;
    }

    double perimetr_square() {
        return 4 * side;
    }

    double area_square() {
        return side * side;
    }
};

class circleSquare : public circle, public square {

public:
    circleSquare() : circle(), square() {
        //...
    }
    circleSquare(int radius, int side) : circle(radius), square(side) {
        //...
    }

    void set() {
        circle::set();
        square::set();
    }
};

int main() {

    /*flying_car fc("fc wheels", "fc wings");

    fc.drive();
    fc.fly();

    cout << fc.get_wheels() << "\n"
        << fc.get_wings();*/

    circleSquare cs;

    cs.set();

    cout << cs.circle::get() << "\n"
        << cs.square::get() << "\n"
    << cs.perimetr_circle() << "\n"
        << cs.perimetr_square()<< "\n"
    << cs.area_circle() << "\n"
        << cs.area_square(); 




    return 0;
}