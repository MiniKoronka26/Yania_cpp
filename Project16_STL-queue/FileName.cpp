#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class client {
    string name;
    int priority;
public:
    client() {
        name = "no set name";
        priority = 0;
    }
    client(string name, int priority) {
        this->name = name;
        this->priority = priority;
    }

    void print() const {
        cout << "priority: " << priority << "| name: " << name;
    }

    int get_priority() const {
        return priority;
    }

};

bool operator>(const client& first, const client& second) {
    return first.get_priority() > second.get_priority();
}

bool operator<(const client& first, const client& second) {
    return first.get_priority() < second.get_priority();
}



int main() {

    // FIFO

    //BASIC QUEUE   

    /*queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);

    cout << q.front();

    q.pop();

    cout << "; " << q.front();*/

    //PRIORITY QUEUE

    /*priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(4);
    pq.push(3);
    pq.push(10);
    pq.push(6);
    pq.push(5);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }*/

    priority_queue<client> clients;
    int size = 10;

    clients.push(client("John", 7));
    clients.push(client("Jane", 4));
    clients.push(client("Michael", 10));
    clients.push(client("Emily", 1));
    clients.push(client("David", 8));
    clients.push(client("Sarah", 3));
    clients.push(client("Robert", 6));
    clients.push(client("Jessica", 9));
    clients.push(client("William", 2));
    clients.push(client("Laura", 5));

    for(int i = 0; i < size; i++)
    {
        clients.top().print();
        cout << "\n";
        clients.pop();
    }









    return 0;
}