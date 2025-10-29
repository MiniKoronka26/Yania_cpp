#include <iostream>
#include <map>
#include <string>
using namespace std;

//map, multimap


int main() {

    //1

    /*map<int, string> m;

    pair<int, string> p1 = make_pair(2, "hello");

    m.insert(p1);
    m.insert(make_pair(10, "world"));
    m.insert({ 1, "hi" });

    m[5] = "welcome";*/

    /*for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << "\n";
    }

    m.erase(10);

    cout << "\n------------------\n";

    for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << "\n";
    }*/

    // cout << m[5] << " ";

    /*auto it = m.find(4);

    if (it != m.end())
        cout << it->first << ": " << it->second;
    else
        cout << "don`t found!";*/

    //2

    map<string, double> employees = {
        {"Smith", 1200.99},
        {"Stark", 1300.99},
        {"King", 900.99}
    };

    cout << employees["Stark"];



    return 0;
}