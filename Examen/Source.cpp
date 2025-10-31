#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

int menu() {
    line(100);
    cout << "menu";
    line(100);
    cout << "\n";
    cout << "0 - Exit Program\n";
    cout << "1 - Add New Car\n";
    cout << "2 - Print All Cars\n";
    cout << "3 - Sort by Price\n";
    cout << "3 - Sort by Year\n";
    cout << "3 - Sort by engineVolume\n";
    cout << "4 - Run Test Search (by Name)\n";

    int choice;
    cout << "\nEnter choise: ";
    cin >> choice;
    return choice;
}

class car {
    string name;
    int year;
    double engineVolume;
    double price;
public:

    car() {
        name = "no set name";
        year = engineVolume = price = 0;
    }

    car(string name,
    int year,
    double engineVolume,
    double price) {
        this->name = name;
        this->year = year;
        this->engineVolume = engineVolume;
        this->price = price;
    }

    void print() const {
        line(100);
        cout << "name: " << name 
            << "\nyear: " << year 
            << "\nengineVolume: " << fixed << setprecision(2) << engineVolume 
            << "\nprice: " << fixed << setprecision(2) << price;
        line(100);
    }
    
    string get_name() const {
        return name;
    }

    int get_year() const {
        return year;
    }

    double get_engineVolume() const {
        return engineVolume;
    }

    double get_price() const {
        return price;
    }

};

class dealership {
    vector<car> v;  
public:

    dealership(vector<car> v) {
        this->v = v;
    }

    void add_car(car add) {
        v.push_back(add);
    }

    void delete_car(string name) {
        auto it = remove(v.begin(), v.end(), name);
        v.erase(it, v.end());
    }

    void print() const {
        for (auto el : v)
            el.print();
    }

    car find_by_name(string f) {
        auto res = find(v.begin(), v.end(), [](string name) {
            return name;
            });

        if (res != v.end()) {
            return *res;
        }
        throw exception("not found");
    }

    car find_by_year(int y) {
        auto res = find(v.begin(), v.end(), [](int y) {
            return y;
            });

        if (res != v.end()) {
            return *res;
        }
        throw exception("not found");
    }

    car find_by_year(double ev) {
        auto res = find(v.begin(), v.end(), [](double ev) {
            return ev;
            });

        if (res != v.end()) {
            return *res;
        }
        throw exception("not found");
    }

    car find_by_price(double p) {
        auto res = find(v.begin(), v.end(), [](double p) {
            return p;
            });

        if (res != v.end()) {
            return *res;
        }
        throw exception("not found");
    }

    void sort_price() {
        sort(v.begin(), v.end(), [](car car1, car car2) {
            return car1.get_price() > car2.get_price();
            });
    }

    void sort_year() {
        sort(v.begin(), v.end(), [](car car1, car car2) {
            return car1.get_year() > car2.get_year();
            });
    }

    void sort_engineVolume() {
        sort(v.begin(), v.end(), [](car car1, car car2) {
            return car1.get_engineVolume() > car2.get_engineVolume();
            });
    }

};

int main() {

    /*car c("Toyota", 2015, 15.35, 5555.00);
    c.print();*/


    /*vector<car> v;

    dealership d(v);

    try {
        car c = d.find_by_name("aaa");
        c.print();
    }
    catch (exception ex) {
        cout << ex.what();
    }*/

    vector<car> v = {
        car("Toyota Camry", 2020, 2.5, 25000.00),
        car("Honda Civic", 2022, 1.8, 22000.00),
        car("Tesla Model 3", 2023, 0.0, 45000.00)        
    };

    dealership d(v);

    try {
        car c = d.find_by_name("aaa");
        c.print();
    }
    catch (exception ex) {
        cout << ex.what();
    }

    do {
        system("cls");


        int choice = menu();
        if (!choice) break;
        switch (choice)
        {
        case 1:
            d.add_car(car("Tesla Model 3", 2023, 0.0, 45000.00));
            break;
        case 2:
            d.print();
            break;
        case 3:
            d.sort_price();
            break;
        case 4:
            d.sort_year();
            break;
        case 5:
            d.sort_engineVolume();
            break;
        case 6:
            d.find_by_price();
            break;
        case 7:
            d.find_by_year();
            break;
        case 8:
            d.find_by_engineVolume();
            break;
        default:
            cout << "Incorrect input";
            break;
        }
    } while (true);

    return 0;
}