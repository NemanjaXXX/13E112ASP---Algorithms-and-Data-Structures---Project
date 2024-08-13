#pragma once
#include<iostream>
#include<fstream>
#include"Set.h"
using namespace std;

class Tree :public Set {

	struct Node {
		long long key;
		struct Node* right, * left;
		Node(long long k = 0, Node* r = nullptr, Node* l = nullptr) :key(k), right(r), left(l) {}
	};

	struct Stack {
		Node* node;
		struct Stack* next;
		Stack(Node* n, Stack* nx = nullptr) :node(n), next(nx) {}
	};
	Node* header;
	Stack* sp; // stack_pointer



public:
	Tree() {
		header = new Node();
		sp = nullptr;

	}
	~Tree() {

		if (header->key > 0) {
			delete_tree();
		}
		delete header;
		header = nullptr;

	}

	bool search_elem(long long key_s)const {
		Node* p = header->right;
		while (p != nullptr && key_s != p->key) {
			if (key_s < p->key) {
				p = p->left;
			}
			else {
				p = p->right;
			}

		}
		if (p == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	void insert_elem(long long key_i) {

		Node* p = header->right;
		Node* q = nullptr;
		Node* new_node = new Node(key_i);


		while (p != nullptr) {
			q = p;
			if (new_node->key == p->key) {
				cout << " ERROR: KEY EXIST." << endl;
				return;
			}
			else if (new_node->key < p->key) {
				p = p->left;
			}
			else {
				p = p->right;
			}


		}

		if (q == nullptr) {
			header->right = new_node;
			//header->key++;
		}
		else {
			if (new_node->key < q->key) {
				q->left = new_node;
				//header->key++;
			}
			else {
				q->right = new_node;
				//header->key++;
			}
		}
		header->key++;

	}

	void delete_elem(long long key_d) {
		Node* p = header->right, * rp, * f, * s;
		Node* q = nullptr;

		while (p != nullptr && key_d != p->key) {
			q = p;
			if (key_d < p->key) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		if (p == nullptr) {
			cout << "ERROR: Key is not founded." << endl;
			return;

		}

		if (p->left == nullptr) {
			rp = p->right;

		}
		else if (p->right == nullptr) {
			rp = p->left;
		}
		else {
			f = p;
			rp = p->right;
			s = rp->left;
			while (s != nullptr) {
				f = rp;
				rp = s;
				s = rp->left;
			}
			if (f != p) {
				f->left = rp->right;
				rp->right = p->right;
			}
			rp->left = p->left;
		}



		if (q == nullptr) {
			header->right = rp;
		}
		else if (p == q->left) {
			q->left = rp;
		}
		else {
			q->right = rp;
		}
		delete p;
		header->key--;
	}

	void delete_elem_scope(long long a, long long b) { // Izuzetak ako je a>b.


		for (; a != b; a++) {
			if (search_elem(a)) {
				delete_elem(a);
			}

		}
	}

	long long number_elem()const {
		return header->key;
	}

	// Stack functions: PUSH, POP, STACK_EMPTY

	void PUSH(Node* v) {
		Stack* p;
		p = new Stack(v);
		p->next = sp;
		sp = p;

	}
	Node* POP() { // Izuzetak ako uzima sa praznog steka.
		Stack* p = sp;
		Node* r;
		r = sp->node;
		sp = sp->next;
		delete p;
		return r;

	}

	bool STACK_EMPTY() {
		if (sp == nullptr) return true;
		else return false;
	}

	void difference_trre(Tree& t1, Tree& t2) { // PREORDER
		if (header->right != nullptr) delete_tree();
		Node* next;
		t1.PUSH(t1.header->right);
		while (!t1.STACK_EMPTY()) {
			next = t1.POP();
			while (next != nullptr) {
				if (!t2.search_elem(next->key)) {
					insert_elem(next->key);
				}
				if (next->right != nullptr) {
					t1.PUSH(next->right);
				}
				next = next->left;
			}

		}

		next = header->right;
		while (1) {
			while (next != nullptr) {
				PUSH(next);
				next = next->left;
			}
			if (!STACK_EMPTY()) { //Ovde ispisuje
				next = POP();
				//				cout << next->key << " ";
				next = next->right;
			}
			else {
				break;
			}

		}

	}

	friend ostream& operator<<(ostream& it, Tree& t) { // INORDER
		Node* next = t.header->right;
		while (1) {
			while (next != nullptr) {
				t.PUSH(next);
				next = next->left;
			}
			if (!t.STACK_EMPTY()) {
				next = t.POP();
				it << next->key << " ";
				next = next->right;
			}
			else {
				break;
			}

		}
		return it;
	}


	// Programms for work with files.

	void reading_file() {
		ifstream file;
		int readed;


		file.open("input.txt");

		if (!file.is_open()) {
			cout << "File is not opened successfuly." << endl; // izuzetak
			return;
		}

		while (!file.eof()) {
			file >> readed;
			insert_elem(readed);
		}
		file.close();

	}


	void write_in_file() {

		ofstream output;

		output.open("output.txt");

		if (!output.is_open()) {
			cout << "File is not created successfuly." << endl;
		}

		output << *this;
		output.close();


	}

	friend ofstream& operator<<(ofstream& ofs, Tree& t) {
		Node* next = t.header->right;
		while (1) {
			while (next != nullptr) {
				t.PUSH(next);
				next = next->left;
			}
			if (!t.STACK_EMPTY()) {
				next = t.POP();
				ofs << next->key << " ";
				next = next->right;
			}
			else {
				break;
			}

		}
		return ofs;
	}



	void delete_tree() {
		Node* nxt = header->right;
		while (nxt != nullptr) {
			PUSH(nxt);
			nxt = nxt->left;
		}

		while (!STACK_EMPTY()) {
			nxt = POP();
			if (nxt->key > 0) {
				nxt->key = -nxt->key;
				PUSH(nxt);
				nxt = nxt->right;
				while (nxt != nullptr) {
					PUSH(nxt);
					nxt = nxt->left;
				}
			}
			else {
				nxt->key = -nxt->key;
				delete nxt;
			}
		}





	}


};





