#include <iostream>
using namespace std;


void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

template<class T>
class vector {
    T* data;
    int size;
public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(int size) {
        for (int i = 0; i < size; i++)
            add_element_end(rand() % 101 - 50);
    }

    vector(const vector<T>& other) {
        this->data = new T[other.size];
        size = other.size;
        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }

    }

    int get_size() const {
        return size;
    }


    void add_element_end(T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }



    void add_element_start(T number) {
        T* p = new T[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    vector<T> operator=(const vector<T>& other) {

        if (this == &other)
            return *this;

        if (this->data)
            delete[] this->data;

        this->data = new T[other.size];

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }

        this->size = other.size;

        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    /*T& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }*/

    void print() const {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i);
        line(100);
    }



    ~vector() {
        delete[] data;
    }
};

template<class T>
ostream& operator << (ostream& os, const vector<T>& obj) {
    obj.print();
    return os;
}

template<class T>
istream& operator >> (istream& is, vector<T>& obj) {
    for (int i = 0; i < obj.get_size(); i++)
    {
        cout << "enter number: ";
        is >> obj[i];
    }
    return is;
}

template<class T>
class point {
    T x, y;
public:
    point() { x = y = 0; }
    point(T x, T y) {
        this->x = x;
        this->y = y;
    }

    void print() const {
        cout << "x: " << x << " y: " << y << "\n";
    }
};

template<class T>
ostream& operator << (ostream& os, const point<T>& obj) {
    obj.print();
    return os;
}


int main() {
    setlocale(LC_CTYPE, "ukr");
    srand(time(0));

    /*vector<int> v;
    v.add_element_end(100);
    v.add_element_end(500);
    v.add_element_end(300);
    v.add_element_end(400);
    v.add_element_end(200);

    v.print();

    vector<double> v2;
    v2.add_element_end(1.23);
    v2.add_element_end(2.54);
    v2.add_element_end(6.35);
    v2.add_element_end(8.51);
    v2.add_element_end(3.97);

    v2.print();*/

    vector<point<int>> points;
    points.add_element_end(point<int>(3, 4));
    points.add_element_end(point<int>(9, 3));
    points.add_element_end(point<int>(-3, 1));
    points.add_element_end(point<int>(-11, 4));
    points.add_element_end(point<int>(7, 1));
    points.print();

    vector<point<double>> points2;
    points2.add_element_end(point<double>(3.23, 4.18));
    points2.add_element_end(point<double>(9.62, 3.79));
    points2.add_element_end(point<double>(-3.67, 1.00));
    points2.add_element_end(point<double>(-11.77, 4.90));
    points2.add_element_end(point<double>(7.89, 1.63));
    points2.print();





    return 0;
}