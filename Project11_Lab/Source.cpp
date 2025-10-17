#include <iostream>
#include <string>
using namespace std;

// Бінарне дерево - це ДСД, яка складається із вузлів,
// кожен з яких крім даних містить посилання на декілька інших вузлів
// а саме:
// - посилання на лівого нащадка
// - посилання на правого нащадка
// - посилання на предка

// Алгоритм побудови бінарного дерева:
// Перший елемент вставляється в корінь дерева.
// Якщо наступний елемент більший за попередній, 
// то він вставляєтьяс в праву гілку, 
// якщо менший, то в ліву 

class bus_k {
	int number, //key
		num_v,
		amout;
	string name, surname;
public:

	bus_k() {
		number = num_v = amout;
		name = surname = nullptr;
	}

	bus_k(int number, int num_v, int amout, string name, string surname) {
		this->name = name;
		this->surname = surname;
		this->amout = amout;
		this->number = number;
		this->num_v = num_v;
	}

	void set_number(int key) {
		number = key;
	}
	int get_number() const {
		return number;
	}
};

struct element {
	bus_k data;
	element* parent, * left, * right;

	element() {
		left = right = parent = nullptr;
	}

	element(bus_k data, element* parent, element* left, element* right) {
		this->data = data;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}
};

class bus {
	element* root;
public:

	bus() {
		root = nullptr;
	}

	void insert(element* node) {

		element* ptr = nullptr, * tmp = root;

		while (tmp) {
			ptr = tmp;
			if (node->data.get_number() < tmp->data.get_number())
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		if (!ptr)
			root = node;
		else if (node->data.get_number() < ptr->data.get_number())
			ptr->left = node;
		else
			ptr->right = node;
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

		while (node && node->data.get_number() != key) {
			if (key < node->data.get_number()) node = node->left;
			else node = node->right;
		}
		return node;
	}

	void print(element* node) const {
		if (node) {
			print(node->left);
			cout << node->data.get_number() << " ";
			print(node->right);
		}
	}

	element* get_root() const {
		return root;
	}

};

int main() {

	bus t;

	/*t.insert(100);*/
	/*
	t.insert(95);
	t.insert(107);
	t.insert(12);
	t.insert(99);
	t.insert(102);
	t.insert(108);*/

	t.print(t.get_root());

	/*element* min = t.min(t.get_root());
	if (min)
		cout << "\n" << min->key;

	element* max = t.max(t.get_root());
	if (max)
		cout << "\n" << max->key;

	element* result = t.search(t.get_root(), 99);

	if (result)
		cout << "\n" << result->key;
	else
		cout << "\nNot found";*/



	return 0;
}