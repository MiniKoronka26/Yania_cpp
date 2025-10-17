#include <iostream>
#include <string>
using namespace std;

// Простори імен - це область оголошень данних та типів, 
// яка забезпечує логічний зв'язок між ними 

namespace d2 {
    class point {

    private:
        int x, y;
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

        void set_x(int x_value) {
            x = x_value;
        }

        void set_y(int y_value) {
            y = y_value;
        }
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
}

namespace d3 {
    class point {

    private:
        int x, y, z;
    public:

        static int count;
        static int liveOblects;


        point() {
            x = y = z = 0;
            count++;
        }

        point(int x, int y) {
            this->x = x;
            this->y = y;
            this->z = z;
            count++;
            liveOblects++;
        }


        void set() {
            cout << "Enter x: ";
            cin >> x;
            cout << "Enter y: ";
            cin >> y;
            cout << "Enter z: ";
            cin >> z;
        }

        void set(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        void set_x(int x_value) {
            x = x_value;
        }

        void set_y(int y_value) {
            y = y_value;
        }

        void set_z(int z_value) {
            z = z_value;
        }

        int get_x() {
            return x;
        }

        int get_y() {
            return y;
        }

        int get_z() {
            return z;
        }


        void print() {
            cout << "x: " << x << ", y:" << y << ", z:" << z << "\n";
        }

        ~point() {
            liveOblects--;
        }
    };


    int point::count = 0;
    int point::liveOblects = 0;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

namespace dynamic_data_structures {
    namespace vectors {
        class vector {
            int* data;
            int size;
        public:
            vector() {
                data = nullptr;
                size = 0;
            }

            vector(int size) { // 10
                // this->data = new int[size];
                for (int i = 0; i < size; i++)
                    add_element_end(rand() % 101 - 50);
            }

            vector(const vector& other) {
                this->data = new int[other.size];
                size = other.size;
                for (int i = 0; i < other.size; i++)
                {
                    this->data[i] = other.data[i];
                }

            }

            int get_size() const {
                return size;
            }


            void add_element_end(int number) {
                int* p = new int[size + 1];

                for (int i = 0; i < size; i++)
                    *(p + i) = *(data + i);

                p[size] = number;
                delete[] data;
                data = p;
                size++;
                p = nullptr;
            }



            void add_element_start(int number) {
                int* p = new int[size + 1];

                for (int i = 1; i < size + 1; i++)
                    *(p + i) = *(data + i - 1);

                p[0] = number;

                delete[] data;
                data = p;
                size++;
                p = nullptr;
            }

            vector operator=(const vector& other) {

                if (this == &other)
                    return *this;

                if (this->data)
                    delete[] this->data;

                this->data = new int[other.size];

                for (int i = 0; i < other.size; i++)
                {
                    this->data[i] = other.data[i];
                }

                this->size = other.size;

                return *this;
            }

            int& operator[](unsigned int index) {
                if (index >= size)
                    throw exception("index out of range");

                return data[index];
            }

            int& get_element_by_index(unsigned int index) {
                if (index >= size)
                    throw exception("index out of range");

                return data[index];
            }

            void print() const {
                line(100);
                for (int i = 0; i < size; i++)
                    cout << *(data + i) << " ";
                line(100);
            }



            ~vector() {
                delete[] data;
            }
        };

        ostream& operator << (ostream& os, const vector& obj) {
            obj.print();
            return os;
        }

        istream& operator >> (istream& is, vector& obj) {
            for (int i = 0; i < obj.get_size(); i++)
            {
                cout << "enter number: ";
                is >> obj[i];
            }
            return is;
        }
    }
    namespace list {
        namespace l1{
            struct element {
                int data = 0;
                element* next = nullptr;
            };

            class single_list{
                element* head, * tail;
                int size;
            public:
                single_list() {
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
                        head = new_element;
                        new_element = nullptr;
                    }

                    size++;

                }

                void add_tail(int value) {
                    element* new_element = new element;
                    new_element->data = value;

                    if (size == 0) {
                        head = tail = new_element;
                    }
                    else {
                        tail->next = new_element;
                        tail = new_element;
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
                        size--;
                    }
                }

                void delete_tail() {
                    element* a = head;
                    if (size == 0) {
                        cout << "error";
                    }
                    if (size == 1) {
                        delete_head();
                        return;
                    }
                    else {

                        while (a->next != tail) {
                            a = a->next;
                        }
                        delete tail;
                        tail = a;

                        a->next = nullptr;
                        a = nullptr;

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

                        tmp->next = new_element;

                        size++;
                    }
                }



                void print() const {

                    element* tmp = head;

                    while (tmp) {
                        cout << tmp->data << " ";
                        tmp = tmp->next;
                    }

                }

                ~single_list() {
                    clear();
                }
            };

        }
        namespace l2 {
            struct element {
                int data = 0;
                element* next = nullptr, * prev = nullptr;
            };

            class double_list {
                element* head, * tail;
                int size;
            public:
                double_list() {
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

                ~double_list() {
                    clear();
                }

            };

        }
    }
    namespace queue {
        namespace q1{
            class vector {
            private:
                int* data;
                int size;

            public:
                vector() {
                    data = nullptr;
                    size = 0;
                }

                vector(int size) { // 10
                    // this->data = new int[size];
                    for (int i = 0; i < size; i++)
                        add_element_end(rand() % 101 - 50);
                }

                vector(const vector& other) {
                    this->data = new int[other.size];
                    this->size = other.size;

                    for (int i = 0; i < other.size; i++)
                    {
                        this->data[i] = other.data[i];
                        // *(this->data + i) = *(other.data + i);
                    }
                }

                void print_v() const {
                    line(100);
                    for (int i = 0; i < size; i++)
                        cout << *(data + i) << " ";
                    line(100);
                }

                void set_random(int size) {
                    for (int i = 0; i < size; i++) {
                        add_element_end(rand() % 101 - 50);
                    }
                }

                void add_element_start(int number) {
                    int* p = new int[size + 1];

                    for (int i = 1; i < size + 1; i++)
                        *(p + i) = *(data + i - 1);

                    p[0] = number;

                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void add_element_end(int number) {
                    int* p = new int[size + 1];

                    for (int i = 0; i < size; i++)
                        *(p + i) = *(data + i);

                    p[size] = number;
                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void add_element_need(int place, int number) {
                    int* p = new int[size + 1];

                    for (int i = 0; i < place; i++) {
                        p[i] = data[i];
                    }

                    p[place] = number;

                    for (int i = place; i < size; i++) {
                        p[i + 1] = data[i];
                    }

                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void deletee_element_last() {
                    size--;
                    int* p = new int[size];

                    for (int i = 0; i < size; i++) {
                        p[i] = data[i];
                    }

                    delete[] data;
                    data = p;
                    p = nullptr;
                }

                void deletee_element_first() {
                    size--;
                    int* p = new int[size];

                    for (int i = 0; i < size; i++) {
                        p[i] = data[i + 1];
                    }

                    delete[] data;
                    data = p;
                    p = nullptr;
                }

                void delete_element_position(int position) {
                    int* p = new int[size - 1];

                    for (int i = 0, j = 0; i < size; i++) {
                        if (i != position) {
                            p[j++] = data[i];
                        }
                    }

                    delete[] data;
                    data = p;
                    size--;
                    p = nullptr;
                }

                int search_element_position(int element) {
                    for (int i = 0; i < size; i++)
                        if (data[i] == element)
                            return i;
                    return -1;
                }

                void delete_search_element(int element) {
                    int position = search_element_position(element);
                    if (position != -1)
                        delete_element_position(position);
                    else {
                        cout << "Element not found";
                    }
                }
                void delete_elements_from_position(int count, int position) {
                    for (int i = 0; i < count; i++)
                        delete_element_position(position);
                }

                void delete_array() {
                    delete[] data;
                    data = nullptr;
                    size = 0;
                }

                void change_element_by_value(int number, int change_number) {
                    int position = search_element_position(number);
                    if (position != -1)
                        data[position] = change_number;
                    else {
                        cout << "Not found";
                    }
                }

                void change_element_by_position(int position, int change_number) {
                    data[position] = change_number;
                }

                void reverse_array() {
                    for (int i = 0; i < size / 2; i++) {
                        swap(data[i], data[size - i - 1]);
                    }
                }

                int get_max() {
                    if (size == 0) {
                        cout << "Array is empty\n";
                        return 0;
                    }
                    int max_val = data[0];
                    for (int i = 1; i < size; i++)
                        if (data[i] > max_val)
                            max_val = data[i];
                    return max_val;
                }

                int get_min() {
                    if (size == 0) {
                        cout << "Array is empty\n";
                        return 0;
                    }
                    int min_val = data[0];
                    for (int i = 1; i < size; i++)
                        if (data[i] < min_val)
                            min_val = data[i];
                    return min_val;
                }

                int get_size() const {
                    return size;
                }

                int get_element(int index) {
                    if (index < 0 || index >= size) {
                        cout << "Incorrect index!\n";
                        return 0;
                    }
                    return data[index];
                }

                void sort_asc() {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (data[j] > data[j + 1])
                                swap(data[j], data[j + 1]);
                        }
                    }
                }

                void sort_desc() {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (data[j] < data[j + 1])
                                swap(data[j], data[j + 1]);
                        }
                    }
                }

                void print() {
                    line(100);
                    for (int i = 0; i < size; i++)
                        cout << *(data + i) << " ";
                    line(100);
                }

                void print_info_max() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Max element: " << get_max() << endl;
                }

                void print_info_min() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Min element: " << get_min() << endl;
                }

                void print_info_size() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Size: " << size << endl;
                }

                void print_info_index() {
                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "\n======= ARRAY INFO =======\n";
                    int index;
                    cout << "Enter index: ";
                    cin >> index;

                    int value = get_element(index);
                    cout << "Element at index " << index << " is: " << value << endl;
                }

                vector operator=(const vector& other) {
                    if (this == &other)
                        return *this;

                    if (this->data) {
                        delete[] this->data;
                    }
                    this->data = new int[other.size];

                    for (int i = 0; i < other.size; i++)
                    {
                        this->data[i] = other.data[i];
                    }
                    this->size = other.size;

                    return *this;
                }

                int& get_element_by_index(unsigned int index) {
                    if (index >= size)
                        throw exception("index out of range");

                    return data[index];
                }

                int& operator[](unsigned int index) {
                    if (index >= size)
                        throw exception("index out of range");

                    return data[index];
                }

                bool is_empty() const {
                    return size == 0;
                }


                ~vector() {
                    delete[] data;
                }
            };

            ostream& operator<< (ostream& os, const vector& obj) {
                obj.print_v();
                return os;
            }

            istream& operator>> (istream& is, vector& obj) {
                obj.set_random(10);
                return is;
            }

            class ring_queue {
                vector data;
            public:

                void push(int value)
                {
                    data.add_element_end(value);
                }

                void print() const {
                    data.print_v();
                }

                int top() {
                    if (!is_empty())
                        return data[0];
                    throw exception("Queue is empty");
                }

                bool is_empty() const {
                    return data.is_empty();
                }

                int pop() {
                    if (!is_empty())
                    {
                        int tmp = data[0];

                        data.deletee_element_first();
                        data.add_element_end(tmp);

                        return tmp;
                    }

                    throw exception("Queue is empty");
                }

                void clear() {
                    data.delete_array();
                }

            };
        }
        namespace q2 {
            class vector {
            private:
                int* data;
                int size;

            public:
                vector() {
                    data = nullptr;
                    size = 0;
                }

                vector(int size) { // 10
                    // this->data = new int[size];
                    for (int i = 0; i < size; i++)
                        add_element_end(rand() % 101 - 50);
                }

                vector(const vector& other) {
                    this->data = new int[other.size];
                    this->size = other.size;

                    for (int i = 0; i < other.size; i++)
                    {
                        this->data[i] = other.data[i];
                        // *(this->data + i) = *(other.data + i);
                    }
                }

                void print_v() const {
                    line(100);
                    for (int i = 0; i < size; i++)
                        cout << *(data + i) << " ";
                    line(100);
                }

                void set_random(int size) {
                    for (int i = 0; i < size; i++) {
                        add_element_end(rand() % 101 - 50);
                    }
                }

                void add_element_start(int number) {
                    int* p = new int[size + 1];

                    for (int i = 1; i < size + 1; i++)
                        *(p + i) = *(data + i - 1);

                    p[0] = number;

                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void add_element_end(int number) {
                    int* p = new int[size + 1];

                    for (int i = 0; i < size; i++)
                        *(p + i) = *(data + i);

                    p[size] = number;
                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void add_element_need(int place, int number) {
                    int* p = new int[size + 1];

                    for (int i = 0; i < place; i++) {
                        p[i] = data[i];
                    }

                    p[place] = number;

                    for (int i = place; i < size; i++) {
                        p[i + 1] = data[i];
                    }

                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void deletee_element_last() {
                    size--;
                    int* p = new int[size];

                    for (int i = 0; i < size; i++) {
                        p[i] = data[i];
                    }

                    delete[] data;
                    data = p;
                    p = nullptr;
                }

                void deletee_element_first() {
                    size--;
                    int* p = new int[size];

                    for (int i = 0; i < size; i++) {
                        p[i] = data[i + 1];
                    }

                    delete[] data;
                    data = p;
                    p = nullptr;
                }

                void delete_element_position(int position) {
                    int* p = new int[size - 1];

                    for (int i = 0, j = 0; i < size; i++) {
                        if (i != position) {
                            p[j++] = data[i];
                        }
                    }

                    delete[] data;
                    data = p;
                    size--;
                    p = nullptr;
                }

                int search_element_position(int element) {
                    for (int i = 0; i < size; i++)
                        if (data[i] == element)
                            return i;
                    return -1;
                }

                void delete_search_element(int element) {
                    int position = search_element_position(element);
                    if (position != -1)
                        delete_element_position(position);
                    else {
                        cout << "Element not found";
                    }
                }
                void delete_elements_from_position(int count, int position) {
                    for (int i = 0; i < count; i++)
                        delete_element_position(position);
                }

                void delete_array() {
                    delete[] data;
                    data = nullptr;
                    size = 0;
                }

                void change_element_by_value(int number, int change_number) {
                    int position = search_element_position(number);
                    if (position != -1)
                        data[position] = change_number;
                    else {
                        cout << "Not found";
                    }
                }

                void change_element_by_position(int position, int change_number) {
                    data[position] = change_number;
                }

                void reverse_array() {
                    for (int i = 0; i < size / 2; i++) {
                        swap(data[i], data[size - i - 1]);
                    }
                }

                int get_max() {
                    if (size == 0) {
                        cout << "Array is empty\n";
                        return 0;
                    }
                    int max_val = data[0];
                    for (int i = 1; i < size; i++)
                        if (data[i] > max_val)
                            max_val = data[i];
                    return max_val;
                }

                int get_min() {
                    if (size == 0) {
                        cout << "Array is empty\n";
                        return 0;
                    }
                    int min_val = data[0];
                    for (int i = 1; i < size; i++)
                        if (data[i] < min_val)
                            min_val = data[i];
                    return min_val;
                }

                int get_size() const {
                    return size;
                }

                int get_element(int index) {
                    if (index < 0 || index >= size) {
                        cout << "Incorrect index!\n";
                        return 0;
                    }
                    return data[index];
                }

                void sort_asc() {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (data[j] > data[j + 1])
                                swap(data[j], data[j + 1]);
                        }
                    }
                }

                void sort_desc() {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (data[j] < data[j + 1])
                                swap(data[j], data[j + 1]);
                        }
                    }
                }

                void print() {
                    line(100);
                    for (int i = 0; i < size; i++)
                        cout << *(data + i) << " ";
                    line(100);
                }

                void print_info_max() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Max element: " << get_max() << endl;
                }

                void print_info_min() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Min element: " << get_min() << endl;
                }

                void print_info_size() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Size: " << size << endl;
                }

                void print_info_index() {
                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "\n======= ARRAY INFO =======\n";
                    int index;
                    cout << "Enter index: ";
                    cin >> index;

                    int value = get_element(index);
                    cout << "Element at index " << index << " is: " << value << endl;
                }

                vector operator=(const vector& other) {
                    if (this == &other)
                        return *this;

                    if (this->data) {
                        delete[] this->data;
                    }
                    this->data = new int[other.size];

                    for (int i = 0; i < other.size; i++)
                    {
                        this->data[i] = other.data[i];
                    }
                    this->size = other.size;

                    return *this;
                }

                int& get_element_by_index(unsigned int index) {
                    if (index >= size)
                        throw exception("index out of range");

                    return data[index];
                }

                int& operator[](unsigned int index) {
                    if (index >= size)
                        throw exception("index out of range");

                    return data[index];
                }

                bool is_empty() const {
                    return size == 0;
                }


                ~vector() {
                    delete[] data;
                }
            };

            ostream& operator<< (ostream& os, const vector& obj) {
                obj.print_v();
                return os;
            }

            istream& operator>> (istream& is, vector& obj) {
                obj.set_random(10);
                return is;
            }

            class s1mple_queue {
                vector data;
            public:

                void push(int value)
                {
                    data.add_element_end(value);
                }

                void print() const {
                    data.print_v();
                }

                int top() {
                    if (!is_empty())
                        return data[0];
                    throw exception("Queue is empty");
                }

                bool is_empty() const {
                    return data.is_empty();
                }

                int pop() {
                    if (!is_empty())
                    {
                        int tmp = data[0];

                        data.deletee_element_first();

                        return tmp;
                    }

                    throw exception("Queue is empty");
                }

                void clear() {
                    data.delete_array();
                }

            };
        }
        namespace q3 {
            class priority_item {
                int data;
                int priority;

            public:
                priority_item() {
                    data = 0;
                    priority = 0;
                }

                priority_item(int data, int priority) {
                    this->data = data;
                    this->priority = priority;
                }

                int get_priority() const {
                    return priority;
                }

                void print() const {
                    cout << "Data: " << data << ", Priority: " << priority << "\n";
                }

            };


            ostream& operator<< (ostream& os, const priority_item& obj) {
                obj.print();
                return os;
            }

            class vector {
            private:
                priority_item* data;
                int size;

            public:
                vector() {
                    data = nullptr;
                    size = 0;
                }



                vector(const vector& other) {
                    this->data = new priority_item[other.size];
                    this->size = other.size;

                    for (int i = 0; i < other.size; i++)
                    {
                        this->data[i] = other.data[i];
                        // *(this->data + i) = *(other.data + i);
                    }
                }

                void print_v() const {
                    line(100);
                    for (int i = 0; i < size; i++)
                        cout << *(data + i) << " ";
                    line(100);
                }



                void add_element_start(priority_item number) {
                    priority_item* p = new priority_item[size + 1];

                    for (int i = 1; i < size + 1; i++)
                        *(p + i) = *(data + i - 1);

                    p[0] = number;

                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void add_element_end(priority_item number) {
                    priority_item* p = new priority_item[size + 1];

                    for (int i = 0; i < size; i++)
                        *(p + i) = *(data + i);

                    p[size] = number;
                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void add_element_need(int wher, priority_item number) {
                    priority_item* p = new priority_item[size + 1];

                    for (int i = 0; i < wher; i++) {
                        p[i] = data[i];
                    }

                    p[wher] = number;

                    for (int i = wher; i < size; i++) {
                        p[i + 1] = data[i];
                    }

                    delete[] data;
                    data = p;
                    size++;
                    p = nullptr;
                }

                void deletee_element_last() {
                    size--;
                    priority_item* p = new priority_item[size];

                    for (int i = 0; i < size; i++) {
                        p[i] = data[i];
                    }

                    delete[] data;
                    data = p;
                    p = nullptr;
                }

                void deletee_element_first() {
                    size--;
                    priority_item* p = new priority_item[size];

                    for (int i = 0; i < size; i++) {
                        p[i] = data[i + 1];
                    }

                    delete[] data;
                    data = p;
                    p = nullptr;
                }

                void delete_element_position(int position) {
                    priority_item* p = new priority_item[size - 1];

                    for (int i = 0, j = 0; i < size; i++) {
                        if (i != position) {
                            p[j++] = data[i];
                        }
                    }

                    delete[] data;
                    data = p;
                    size--;
                    p = nullptr;
                }

                void delete_elements_from_position(int count, int position) {
                    for (int i = 0; i < count; i++)
                        delete_element_position(position);
                }

                void delete_array() {
                    delete[] data;
                    data = nullptr;
                    size = 0;
                }


                int get_size() const {
                    return size;
                }

                void print() {
                    line(100);
                    for (int i = 0; i < size; i++)
                        cout << *(data + i) << " ";
                    line(100);
                }


                void print_info_size() {
                    cout << "\n======= ARRAY INFO =======\n";

                    if (size == 0) {
                        cout << "Array is empty!\n";
                        return;
                    }
                    cout << "Size: " << size << endl;

                }


                vector operator=(const vector& other) {
                    if (this == &other)
                        return *this;

                    if (this->data) {
                        delete[] this->data;
                    }
                    this->data = new priority_item[other.size];

                    for (int i = 0; i < other.size; i++)
                    {
                        this->data[i] = other.data[i];
                    }
                    this->size = other.size;

                    return *this;
                }

                priority_item& get_element_by_index(unsigned int index) {
                    if (index >= size)
                        throw exception("index out of range");

                    return data[index];
                }

                priority_item& operator[](unsigned int index) {
                    if (index >= size)
                        throw exception("index out of range");

                    return data[index];
                }



                bool is_empty() const {
                    return size == 0;
                }


                ~vector() {
                    delete[] data;
                }
            };

            ostream& operator<< (ostream& os, const vector& obj) {
                obj.print_v();
                return os;
            }

            class priority_queue {
                vector data;
            public:

                void push(priority_item value) {

                    if (is_empty())
                        data.add_element_start(value);
                    else {
                        int i = 0;
                        while (i < data.get_size() && data[i].get_priority() <= value.get_priority()) {
                            i++;
                        }
                        data.add_element_need(i, value);
                    }
                }

                void print() const {
                    data.print_v();
                }

                priority_item top() {
                    if (!is_empty())
                        return data[0];

                    throw exception("Queue is empty");
                }


                bool is_empty() const {
                    return data.is_empty();
                }

                priority_item pop() {
                    if (!is_empty()) {
                        priority_item tmp = data[0];
                        data.deletee_element_first();
                        return tmp;
                    }
                    throw exception("Queue is empty");
                }

                void clear() {
                    data.delete_array();
                }


            };

        }
    
    }
    namespace stack {
        class vector {
        private:
            int* data;
            int size;

        public:
            vector() {
                data = nullptr;
                size = 0;
            }

            vector(int size) { // 10
                // this->data = new int[size];
                for (int i = 0; i < size; i++)
                    add_element_end(rand() % 101 - 50);
            }

            vector(const vector& other) {
                this->data = new int[other.size];
                this->size = other.size;

                for (int i = 0; i < other.size; i++)
                {
                    this->data[i] = other.data[i];
                    // *(this->data + i) = *(other.data + i);
                }
            }

            void print_v() const {
                line(100);
                for (int i = 0; i < size; i++)
                    cout << *(data + i) << " ";
                line(100);
            }

            void set_random(int size) {
                for (int i = 0; i < size; i++) {
                    add_element_end(rand() % 101 - 50);
                }
            }

            void add_element_start(int number) {
                int* p = new int[size + 1];

                for (int i = 1; i < size + 1; i++)
                    *(p + i) = *(data + i - 1);

                p[0] = number;

                delete[] data;
                data = p;
                size++;
                p = nullptr;
            }

            void add_element_end(int number) {
                int* p = new int[size + 1];

                for (int i = 0; i < size; i++)
                    *(p + i) = *(data + i);

                p[size] = number;
                delete[] data;
                data = p;
                size++;
                p = nullptr;
            }

            void add_element_need(int place, int number) {
                int* p = new int[size + 1];

                for (int i = 0; i < place; i++) {
                    p[i] = data[i];
                }

                p[place] = number;

                for (int i = place; i < size; i++) {
                    p[i + 1] = data[i];
                }

                delete[] data;
                data = p;
                size++;
                p = nullptr;
            }

            void deletee_element_last() {
                size--;
                int* p = new int[size];

                for (int i = 0; i < size; i++) {
                    p[i] = data[i];
                }

                delete[] data;
                data = p;
                p = nullptr;
            }

            void deletee_element_first() {
                size--;
                int* p = new int[size];

                for (int i = 0; i < size; i++) {
                    p[i] = data[i + 1];
                }

                delete[] data;
                data = p;
                p = nullptr;
            }

            void delete_element_position(int position) {
                int* p = new int[size - 1];

                for (int i = 0, j = 0; i < size; i++) {
                    if (i != position) {
                        p[j++] = data[i];
                    }
                }

                delete[] data;
                data = p;
                size--;
                p = nullptr;
            }

            int search_element_position(int element) {
                for (int i = 0; i < size; i++)
                    if (data[i] == element)
                        return i;
                return -1;
            }

            void delete_search_element(int element) {
                int position = search_element_position(element);
                if (position != -1)
                    delete_element_position(position);
                else {
                    cout << "Element not found";
                }
            }
            void delete_elements_from_position(int count, int position) {
                for (int i = 0; i < count; i++)
                    delete_element_position(position);
            }

            void delete_array() {
                delete[] data;
                data = nullptr;
                size = 0;
            }

            void change_element_by_value(int number, int change_number) {
                int position = search_element_position(number);
                if (position != -1)
                    data[position] = change_number;
                else {
                    cout << "Not found";
                }
            }

            void change_element_by_position(int position, int change_number) {
                data[position] = change_number;
            }

            void reverse_array() {
                for (int i = 0; i < size / 2; i++) {
                    swap(data[i], data[size - i - 1]);
                }
            }

            int get_max() {
                if (size == 0) {
                    cout << "Array is empty\n";
                    return 0;
                }
                int max_val = data[0];
                for (int i = 1; i < size; i++)
                    if (data[i] > max_val)
                        max_val = data[i];
                return max_val;
            }

            int get_min() {
                if (size == 0) {
                    cout << "Array is empty\n";
                    return 0;
                }
                int min_val = data[0];
                for (int i = 1; i < size; i++)
                    if (data[i] < min_val)
                        min_val = data[i];
                return min_val;
            }

            int get_size() const {
                return size;
            }

            int get_element(int index) {
                if (index < 0 || index >= size) {
                    cout << "Incorrect index!\n";
                    return 0;
                }
                return data[index];
            }

            void sort_asc() {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (data[j] > data[j + 1])
                            swap(data[j], data[j + 1]);
                    }
                }
            }

            void sort_desc() {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (data[j] < data[j + 1])
                            swap(data[j], data[j + 1]);
                    }
                }
            }

            void print() {
                line(100);
                for (int i = 0; i < size; i++)
                    cout << *(data + i) << " ";
                line(100);
            }

            void print_info_max() {
                cout << "\n======= ARRAY INFO =======\n";

                if (size == 0) {
                    cout << "Array is empty!\n";
                    return;
                }
                cout << "Max element: " << get_max() << endl;
            }

            void print_info_min() {
                cout << "\n======= ARRAY INFO =======\n";

                if (size == 0) {
                    cout << "Array is empty!\n";
                    return;
                }
                cout << "Min element: " << get_min() << endl;
            }

            void print_info_size() {
                cout << "\n======= ARRAY INFO =======\n";

                if (size == 0) {
                    cout << "Array is empty!\n";
                    return;
                }
                cout << "Size: " << size << endl;
            }

            void print_info_index() {
                if (size == 0) {
                    cout << "Array is empty!\n";
                    return;
                }
                cout << "\n======= ARRAY INFO =======\n";
                int index;
                cout << "Enter index: ";
                cin >> index;

                int value = get_element(index);
                cout << "Element at index " << index << " is: " << value << endl;
            }

            vector operator=(const vector& other) {
                if (this == &other)
                    return *this;

                if (this->data) {
                    delete[] this->data;
                }
                this->data = new int[other.size];

                for (int i = 0; i < other.size; i++)
                {
                    this->data[i] = other.data[i];
                }
                this->size = other.size;

                return *this;
            }

            int& get_element_by_index(unsigned int index) {
                if (index >= size)
                    throw exception("index out of range");

                return data[index];
            }

            int& operator[](unsigned int index) {
                if (index >= size)
                    throw exception("index out of range");

                return data[index];
            }

            bool is_empty() const {
                return size == 0;
            }


            ~vector() {
                delete[] data;
            }
        };

        ostream& operator<< (ostream& os, const vector& obj) {
            obj.print_v();
            return os;
        }

        istream& operator>> (istream& is, vector& obj) {
            obj.set_random(10);
            return is;
        }

        class stack {
            vector data;
        public:

            void push(int value)
            {
                data.add_element_start(value);
            }

            void print() const {
                data.print_v();
            }

            int top() {
                if (!is_empty())
                    return data[0];
                throw exception("Stack is empty");
            }

            bool is_empty() const {
                return data.is_empty();
            }

            int pop() {
                if (!is_empty())
                {
                    int tmp = data[0];

                    data.deletee_element_first();

                    return tmp;
                }

                throw exception("Stack is empty");
            }

            void clear() {
                data.delete_array();
            }

        };
    }
    namespace binary_tree {
        struct element {
            int key;
            element* parent, * left, * right;

            element() {
                key = 0;
                left = right = parent = nullptr;
            }
        };

        class tree {
            element* root;
            int count;
        public:

            tree() {
                root = nullptr;
                count = 0;
            }

            void insert(int key) {
                element* node = new element;
                node->key = key;

                element* ptr = nullptr, * tmp = root;

                while (tmp) {
                    ptr = tmp;
                    if (node->key < tmp->key)
                        tmp = tmp->left;
                    else
                        tmp = tmp->right;
                }
                if (!ptr)
                    root = node;
                else if (node->key < ptr->key)
                    ptr->left = node;
                else
                    ptr->right = node;

                count++;
            }

            element* min(element* node) const {
                if (node)
                {
                    while (node->left)
                        node = node->left;

                }
                return node;

            }

            element* max(element* node) const {
                if (node)
                {
                    while (node->right) {
                        node = node->right;
                    }
                }
                return node;

            }

            element* search(element* node, int key) {

                while (node && node->key != key) {
                    if (key < node->key) node = node->left;
                    else node = node->right;
                }
                return node;
            }

            void print(element* node) const {
                if (node) {
                    print(node->left);
                    cout << node->key << " ";
                    print(node->right);
                }
            }

            element* get_root() const {
                return root;
            }

        };
    }
}

int main() {

    /*d2::point p1;
    p1.set();
    d3::point p2;
    p2.set();

    p1.print();
    p2.print();*/

    dynamic_data_structures::vectors::vector v;
    dynamic_data_structures::list::l1::single_list l_01;
    dynamic_data_structures::list::l2::double_list l_02;
    dynamic_data_structures::queue::q1::ring_queue q_01;
    dynamic_data_structures::queue::q2::s1mple_queue q_02;
    dynamic_data_structures::queue::q3::priority_queue q_03;
    dynamic_data_structures::stack::stack s;
    dynamic_data_structures::binary_tree::tree t;

    return 0;
}