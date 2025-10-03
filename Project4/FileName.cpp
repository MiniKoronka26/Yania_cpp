#include <iostream>
#include <cmath>
using namespace std;

// Статичні поля - це поля, які використовують мпільно всіма об'єктами класу
// Кажуть, що вони належать не конткр   етному об'єкту, а класу в цілому 

class point {

private:
    // дані, поля
    int x, y;

    // функції, методи
public:

    static int count;
    static int liveOblects;


    point() {
        x = y = 0;
        count++;
    }

    point(int x, int y) {
        this->x = x;
        this->y = y;
        count++;
        liveOblects++;
    }


    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // Методи аксесори

    // Модифікатори
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    // Інспектори
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }


    void print() {
        cout << "X: " << x << ", Y:" << y << "\n";
    }

    ~point() {
        liveOblects--;
    }
};


int point::count = 0;   
int point::liveOblects = 0;

class employee {
    char* surname;
    int id;
    static int id_e;

public:

    employee(const char* surname) {
        id_e++;
        id = id_e;
        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);

    }

    static int get_last_id() {
        return id_e;
    }

    void print() {
        cout << "Surame: " << surname << " || ID: " << id;
    }
};

int employee::id_e = 0;

class my_math {
    
public:
    static const double PI;


    static int sum(int a, int b) {
        return a + b;
    }

    static int sub(int a, int b) {
        return a - b;
    }

    static int mul(int a, int b) {
        return a * b;
    }

    static int div(int a, int b) {
        return a / b;
    }

    static int square(int a, int b) {
        return a^2;
    }
};

const double my_math::PI = 3.14;

class s {
    static int count;
public:
    

    static double s_triangle(double a, double h) {
        count++;
        return 0,5 * h * a;
    }
    static double s_triangle(double a, double b, double c) {
        count++;

        double p = (a + b + c) / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    static double s_rectangle(double a, double b) {
        count++;
        return a * b;
    }

    static double s_square(double a) {
        count++;
        return a * a;
    }
        
    static double s_diamond(double d1, double d2) {
        count++;
        return 0,5 * d1 * d2;
    }

    static int get_count() {
        return count;
    }

};

int s::count = 0;

int main() {
    
    /*point p1(3, 4);
    point p2(1, 0);
    point p3(1, -9);
    
    {
        point p4(1, 2);
    }

    cout << point::count << "\n";
    cout << point::liveOblects << "\n";*/
    

    /*employee e1("John");
    e1.print();
    
    cout << "\n";

    employee e2("Ellie");
    e2.print();

    cout << "\n";

    employee e3("Adam");
    e3.print();

    cout << "\n" << employee::get_last_id();*/

    /*cout << my_math::mul(3, 4) << '\n';

    cout << my_math::PI;*/
    
    cout << "Triangle 1: " << s::s_triangle(3, 4)
        << " || Triangle 2: " << s::s_triangle(3, 4, 5)
        << " || Rectangle: " << s::s_rectangle(3, 4)
        << " || Square: " << s::s_square(3)
        << " || Diamond: " << s::s_diamond(3, 4);

    cout << "\nCount: " << s::get_count();










    return 0;
}