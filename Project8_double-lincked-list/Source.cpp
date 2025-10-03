#include <iostream>
using namespace std;

//Двозв'язний список - це ДСД, в якому об'єкти складаються із елементів,
// що мсістять певну інформацію і два вказівники:
// один на попередній елемент, інший - на наступний

int menu() {

    cout << "\n\n0 - Exit\n";
    cout << "1 - Add Head\n";
    cout << "2 - Add Tail\n";
    cout << "3 - Delete Head\n";
    cout << "4 - Delete Tail\n";
    cout << "5 - Delete\n";
    cout << "6 - Add element pos\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

struct element {
    int data = 0;
    element* next = nullptr, * prev = nullptr;
};

class list {
    element* head, * tail;
    int size;
public:
    list() {
        head = tail = nullptr;
        size = 0;
    }

    void set(int size) {
        for (int i = 0; i < size; i++)
        {
            add_head(get_random_number(-50, 100));
        }
    }

    void add_head(int value) {

        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head->prev = new_element;
            head = new_element;
            new_element = nullptr;
        }

        size++;
    }

    void add_tail(int value) {
        element* new_element = new element;
        
        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->prev = tail;
            tail->next = new_element;
            tail = new_element;
            new_element->data = value;
            new_element = nullptr;
        }
        size++;
    }

    void delete_head() {
        element* h = head;
        if (size == 0) {
            cout << "error";
        }
        else {
            head = head->next;
            delete h;
            if (size != 1)
                tail->prev = 0;
            size--;
        }
    }

    void delete_tail() {
        element* t = tail;
        if (size == 0) {
            cout << "error";
        }
        if (size == 1) {
            delete_head();
            return;
        }
        else {
            tail = tail->prev;
            tail->next = 0;
            delete t;
            size--;
        }
    }

    void clear() {
        element* a = head;
        if (size == 0) {
            cout << "error";
        }
        else {
            while (size != 0) {
                delete_tail();
            }
        }
    }

    void add_pos(int pos, int value) {

        if (size == 0) add_head(value);
        else if (pos == size) add_tail(value);
        else {
            element* new_element = new element;
            new_element->data = value;

            element* tmp = head;

            int i = 0;
            while (i++ < pos - 1)
                tmp = tmp->next;

            new_element->next = tmp->next;
            new_element->prev = tmp->prev;
            
            tmp->next = new_element;
            tmp->prev = new_element->prev;

            size++;
        }
    }

    void delete_pos(int pos) {
        if (size == 0) {
            cout << "error";
        }
        else {

            element* tmp = head;
            element* a = head;

            int i = 0;
            while (i++ < pos - 1)
                tmp = tmp->next;

            a = tmp->prev;
            tmp->prev = tmp->next;
            tmp->next = a;

            delete tmp;

            size--;
        }
    }


    void print() const {

        element* tmp = head;

        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }

    }

    ~list() {
        clear();
    }

};






int main() {
    srand(time(0));

    int number;

    list l;
    l.set(5);

    do {
        system("cls");
        l.print();

        int choice = menu();
        if (!choice) break;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> number;
            l.add_head(number);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> number;
            l.add_tail(number);
            break;

        case 3:
            l.delete_head();
            break;
        case 4:
            l.delete_tail();
            break;
        case 5:
            l.clear();
            break;
        case 6:
            l.add_pos(2, 3);
            break;
        case 7:
            l.delete_pos(3);
            break;
        default:
            cout << "Incorrect input";
            break;
        }
    } while (true);

    return 0;
}