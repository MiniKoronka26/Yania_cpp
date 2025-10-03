#include <iostream>
using namespace std;

#define NAME_SIZE 100


class stud {
    char* surname;

public:

    stud() {
        surname = new char[NAME_SIZE];

    }

    stud(const char* surname) {

        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);

    }

    //консруктор копіювання 1
    stud(const stud& other) {
        this->surname = new char[strlen(other.surname) + 1];
        strcpy_s(this->surname, strlen(other.surname) + 1, other.surname);
    }

    void set() {

        cout << "enter surname: ";
        gets_s(surname, NAME_SIZE);


    }

    void print() {
        cout << "surname: " << surname;

    }

    ~stud() {
        delete[] surname;
    }

};

// Конструктор копіювання викликається в 3 випадках:
// - Ініціалізація одного об'єкта іншим
// - Передача в якості параметра об'єкта в функцію або метод по значенню
// - Повернення обє'кта з функції або метота по значенню

// Якщо ми виділяємо динамічну пам'ять і потім в деструкторі її 
// звільняємо, то ми маємо описати свій конструктор копіювання

void func1(stud s) {
    //...
}

stud func2() {
    stud s("Jack");
    return s;
}

int main() {

    stud s1("John");
    s1.print();

    cout << "\n";

    //1
    /*stud s2 = s1; 
    s2.print();*/

    //2
    /*func1(s1);
    */

    //3
    stud s2 = func2();
    s2.print();






    return 0;
}