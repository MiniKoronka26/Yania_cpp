#include <iostream>
using namespace std;

class train {
    char number[100];
    char name[100];
    int size_car;
    int* carriages;
public: 
    train() {
        size_car = 0;
        carriages = nullptr;
    }

    train(int size, int* carriages, const char* name, const char* number) {
        size_car = size;
        this->carriages = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->carriages[i] = carriages[i];
        }
        strcpy_s(this->name, name);
        strcpy_s(this->number, number);
    }

    void set() {
        cout << "Enter numberof train: ";
        cin >> number;
        cout << "Enter name of  train: ";
        cin >> name;
        cout << "Enter amount of carriages: ";
        cin >> size_car;
        this->carriages = new int[size_car];

        for (int i = 0; i < size_car; i++)
        {
            cout << "\nEnter peoples in carriage " << i << ": ";
            cin >> carriages[i];
        }

    }


    void print() {
        cout << "Number: " << number << " || Name: " << name << "|| Size of train: " << size_car;
        for (int i = 0; i < size_car; i++)
        {
            cout << "\nPeoples in carriage " << i << ": " << carriages[i];
        }
    }
};

int main() {
    int* carr = new int[5] {1, 2, 3, 4, 5};
    /*train t1(5, carr, "Lviv-Kyiv", "12345");
    t1.print();*/
    train t1;
    t1.set();
    t1.print();
    


    return 0;
}