#include <iostream>
#include <string>
using namespace std;

// Поліморфізм - це здатність коду при постійному інтерфейсі(зовнішньому вигляді)
// працювати по різному, в залежності від ситуації, яка виникає
// на момент виконання програми 

// Раннє зв'язування - тим об'єкта відоми на етамі компіляції і
// виклик метода з кодом цього метода зв'язується на етапі компіляції. 
// Компілятор при ранньому зв'язуванні орієнтується на тип даного.

// Вказівник на батьківсткий клас може вказувати на будь який дочірний клас.

// Якщо зв'язування виклику метода з кодом самого метода відбувається на етапі виконання
// програми, то зв'язування називається пізнім.


//1

class A {
public:
    virtual void func() {
        cout << "class A, func\n";
    }
};

class B : public A {
public:
    void func() override {
        cout << "class B, func\n";
    }
};

class C : public A {
public:
    void func() override {
        cout << "class C, func\n";
    }
};

//2

class vehicle {
protected: 
    string name, color;
public:
    vehicle(string name, string color) {
        this->name = name;
        this->color = color;
    }
    virtual void drive() = 0;
};

class car : public vehicle {
public:
    car(string name, string color) 
        : vehicle(name, color){}
    void drive() override {
        cout << "I am driving " << color << " " << name << " car\n";
    }
};

class bus : public vehicle {
public:
    bus(string name, string color)
        : vehicle(name, color) {}
    void drive() override {
        cout << "I am driving " << color << " " << name << " bus\n";
    }
};

class moto : public vehicle {
public:
    moto(string name, string color)
        : vehicle(name, color) {}
    void drive() override {
        cout << "I am driving " << color << " " << name << " moto\n";
    }
};

//3

class weapon {
public:
    virtual void shoot() {
        cout << "weapon shoot!\n";
    }
};

class gun : public weapon {
public:
    void shoot() override {
        cout << "gun shoot!\n";
    }
};

class rifle : public weapon {
public:
    void shoot() override {
        cout << "rifle shoot!\n";
    }
};

class machine_gun : public weapon {
public:
    void shoot() override {
        cout << "machine_gun shoot!\n";
    }
};

class player {
public:
    void shoot_weapon(weapon* w) { 
        w->shoot();
    }
};

//4

class payment {
public:
    virtual void accept() {
        cout << "aceept money\n";
    }
};

class cash : public payment {
public:
    void accept() override {
        cout << "aceept cash\n";
    }
};

class card : public payment {
public:
    void accept() override {
        cout << "aceept card\n";
    }
};

class nfc : public payment {
public:
    void accept() override {
        cout << "aceept nfc\n";
    }
};

class cash_machine {
public:
    void accept_payment(payment* w) {
        w->accept();
    }
};

// Абстрактні класи



int main() {

    //1

    /*A objA;
    objA.func();

    B objB;
    objB.func();

    C objC;
    objC.func();*/

    /*A objA;
    B objB;
    C objC;*/

    /*A* pA = &objA;
    B* pB = &objB;
    C* pC = &objC;

    pA->func();
    pB->func();
    pC->func();*/

    /*A* pA = nullptr;

    pA = &objB;
    pA->func();
    
    pA = &objC;
    pA->func();*/

    //2

    /*vehicle* v = nullptr;
    car c;
    bus b;
    moto m; 

    cout << "1 - car\n";
    cout << "2 - bus\n";
    cout << "3 - moto\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        v = &c;
        break;
    case 2:
        v = &b;
        break;
    case 3:
        v = &m;
        break;
    default:
        break;
    }
    v->drive();*/

    //3

    /*player p;
    gun g;
    p.shoot_weapon(&g);
    p.shoot_weapon(new rifle);*/

    //4

    /*cash_machine cm;
    cash c;
    cm.accept_payment(&c);*/

    //

    /*vehicle* arr[] = { new car, new bus, new moto };

    for (vehicle* v : arr) {
        v->drive();*/

    //

    vehicle* v = new bus("f12", "red");
    v->drive();
    

    return 0;
}