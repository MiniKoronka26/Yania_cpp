#include <iostream>
#include <string>
using namespace std;

class goods {
protected:
    string name;
    int number;
    int price;
public:
    goods() {
        name = "No set name";
        number, price = 0;
    }

    goods(string name, int number, int price) {
        this->name = name;
        this->number = number;
        this->price = price;
    }
};

class electro : public goods {
    int voltage;
public:
    electro() : goods() {
        voltage = 0;
    }
    electro(string name, int number, int price, int voltage)
        : goods(name, number, price) {
        this->voltage = voltage;
    }
};//laptop/Pc - >game

class food : public goods {
    int calories;
public:
    food() : goods() {
        calories = 0;
    }
    food(string name, int number, int price, int calories)
        : goods(name, number, price) {
        this->calories = calories;
    }
};//швидко

int main() {



    return 0;
}