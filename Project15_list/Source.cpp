#include <iostream>
#include <list>
#include <vector>
using namespace std;

void print(list<int> l) {
    for (int el : l) {
        cout << el << " ";
    }
    cout << "\n";
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0));

    /*list<int> l = { 3, 5, 9, 20, -2, 3, 5 };

    l.push_back(10);
    l.push_front(20);
    l.pop_front();
    l.pop_back();

    l.clear();

    list<int>::iterator it = l.begin();
    it++;
    it--;
    advance(it, 5);
    for (int el : l) {
        cout << el << " ";
    }*/

    /*list<int> l = { 3, 5, 9, 20, -2, 3, 5 };
    list<int>::iterator it = l.begin();

    l.insert(it++, 3);
    l.insert(it++, 2);
    l.insert(it++, 5);

    print(l);

    l.erase(l.begin());
    print(l);

    l.reverse();
    print(l);

    l.sort();
    print(l);*/

    list<int> l;
    list<int>::iterator it = l.begin();

    int size = 10;

    for (int i = 0; i < size; i++) {
        l.push_back(get_random_number(0, 50));
    }

    print(l);



    return 0;
}