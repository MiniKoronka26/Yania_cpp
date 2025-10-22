#include <iostream>
#include <vector>
#include <string>
using namespace std;
// STL(Standart Template Library)

// vector
// list
// queue
// stack
// map, multi_map, set, multi_set
 
// контейнер
// ітератори - це сутності, які потрібні для взаємодії з лементасми та методами контейнера
// алгоритми
// функтори 

//void print_vector(vector<int> v) {
//    for (int el : v)
//        cout << el << " ";
//    cout << "\n";
//}

template<class T>
void print_vector(vector<T> v) {
    for (T el : v)
        cout << el << " ";
    cout << "\n";
}

class point {
    int x, y;
public:
    point() {
        x = y = 0;
    }
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend ostream& operator << (ostream& os, const point& obj);
};

ostream& operator << (ostream& os, const point& obj) {
    os << "x = " << obj.x << " , " << "y = " << obj.y << "\n";
    return os;
}

struct time_d {
    int hour;
    int minute;
    int second;

    time_d() {
        hour = minute = second = 0;
    }

    time_d(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    void print() const {
        cout << "hour: " << hour << ", minute: " << minute << ", second: " << second;
    }
};

class train {
    int number;
    time_d time;
public:
    train() {
        number = 0;
    }
    train(int number, time_d time) {
        this->number = number;
        this->time = time;
    }

    void print() const {
        cout << "\n" << "number: " << number << ", time: \n";
        time.print();
    }

    int get_number() const {
        return number;
    }

};

class system_trains{
    vector<train> trains;
public:

    void print() const {
        int i = 0;
        for (train el : trains) {
            trains[i].print();
            i++;
        }
    } 
     
    void search(int s) const {
        int i = 0;
        for (train el : trains) {
            if (trains[i].get_number() == s)
                break;
            i++;
        }
        trains[i].print();
    }

    void add(train a) {
        trains.push_back(a);
    }


};

int main() {

    /*vector<int> v = { 10, -3, 0, 4, 11, 3 , 9 };

    v.push_back(100);*/

    /*for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";*/

    /*print_vector(v);

      v[3] = 200;
      print_vector(v);

      v.pop_back(); // delete from back
      print_vector(v); */

    /*vector<int>::iterator it = v.begin();

      it++; // переставляємо вперед
      it--; // переставляємо назад
      it + 2; // вказівник на 2 вперед
      it - 2; // вказівник на 2 назав

      it += 10;
      advance(it, 10);*/

    /*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
          cout << *it << " ";
      }

      int i = 0;

      for (vector<int>::iterator it = v.begin(); i < v.size(); i++) {
          cout << *it << " ";
      }*/

    /*vector<int>::iterator it = v.begin();
      cout << *(it + 3);
      it += 3;
      cout << *it;*/

    /*for (vector<int>::const_iterator it = v.begin(); it > v.end(); it++) {
        cout << *it << " ";
    }*/

    //vector<int> v = { 10, -3, 0, 4, 11, 3 , 9 };
    
    // advance
    // distance

    //vector<int>::iterator it = v.begin();

    //advance(it, 2);           //it += 2

    /*advance(it, 5);

    cout << distance(v.begin(), it); //distance between 2 obj*/ 

    /*it += 5;
    v.insert(it, 500);  
    it = v.begin() + 5;
    v.insert(it, 34);
    it = v.begin() + 5;
    v.insert(it, 555);
    it = v.begin() + 5;
    v.insert(it, 3333);
    it = v.begin() + 5;
    v.insert(it, 88);

    print_vector(v);*/

    /*print_vector(v);

    v.erase(v.begin() + 3);

    print_vector(v);*/

    // auto

    /*auto a = 10;

    auto it = v.begin();*/

    /*vector<string> countries = { "USA", "Ukraine", "France", "Spain", "Germany" };

    auto it = countries.begin();

    countries.insert(it, "Italy");

    print_vector(countries);*/

    /*vector<point> points = { point(1, 2), point(3, 4), point(5, 6) };
    print_vector(points);*/

    /*vector<int> numbers;
    int size = 10;
    for (int i = 1; i <= size; i++)
        numbers.push_back(i * i);
    print_vector(numbers); */

    /*int rows = 10, cols = 10;
    vector<vector<int>> v(rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            v[i].push_back(i * j);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }*/

    //Task

    system_trains t;
    t.add(train(156, time_d(03, 05, 55)));
    t.add(train(439, time_d(12, 56, 00)));
    t.add(train(156, time_d(18, 12, 13)));
    t.print();
    cout << "\n\n------info------";
    t.search(156);



    return 0;
}