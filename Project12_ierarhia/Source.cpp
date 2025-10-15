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
};

class pc : public electro {
    bool game; // 1 - pc for game; 0 - basic pc
public:
    pc() : electro() {
        game = false;
    }
    pc(string name, int number, int price, int voltage, bool game)
        : electro(name, number, price, voltage) {
        this->game = game;
    }
};

class printer : public electro {
    bool color_or_not; // 1 - Rgb; 0 - no rgb
public:
    printer() : electro() {
        color_or_not = false;
    }
    printer(string name, int number, int price, int voltage, bool color_or_not)
        : electro(name, number, price, voltage) {
        this->color_or_not = color_or_not;
    }
};

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