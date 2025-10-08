#include <iostream>
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

int main() {

	tree t;

	t.insert(100);
	t.insert(95);
	t.insert(107);
	t.insert(12);
	t.insert(99);
	t.insert(102);
	t.insert(108);

	t.print(t.get_root());

	element* min =  t.min(t.get_root());
	if (min)
		cout << "\n" << min->key;

	element* max =  t.max(t.get_root());
	if(max)
		cout << "\n" << max->key;

	element* result = t.search(t.get_root(), 99);

	if (result)
		cout << "\n" << result->key;
	else
		cout << "\nNot found";



	return 0;
}