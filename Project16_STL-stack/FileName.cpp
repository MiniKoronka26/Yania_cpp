#include <iostream>
#include <stack>
#include <string>
using namespace std;



int main() {

    // LIFO

    stack<int> s1;
    stack<int> s2;

    s1.push(4);
    s1.push(10);
    s1.push(5);
    s1.push(7);

    s2.push(33);
    s2.push(9);

    cout << s1.top();

    s1.pop();

    cout << " " << s1.top();

    s1.swap(s2);

    cout << s1.top() << "\n" << s2.top();


    return 0;
}