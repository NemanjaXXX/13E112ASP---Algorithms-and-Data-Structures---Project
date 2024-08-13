#pragma once
#include<iostream>
#include<fstream>
#include"Set.h"
using namespace std;



class List : public Set {

	struct Elem {
		long long data;
		struct Elem* next;
		Elem(long long d, Elem* n = nullptr) :data(d), next(n) {}
	};
	Elem* header;
public:


	List() {
		header = new Elem(0);
	}


	~List() {
		if (header->data > 0) {
			delete_set();

		}
		delete header;
		header = nullptr;
	}

	bool search_elem(long long key_s) const override {
		if (header->data == 0) return false;
		if (header->data == 1)
			if (key_s == header->next->data) return true;
			else return false;
		long long i = header->data;
		Elem* current = header->next->next;
		while (i-- && current->data < key_s) {
			current = current->next;
		}
		if (current->data == key_s) return true;
		else return false;

	}


	void insert_elem(long long key_i)override {

		//Implementation using circular signle linked list 
		Elem* new_elem, * current, * previous, * first;
		long long end = header->data;
		//if (search_elem(key_i))return;
		new_elem = new Elem(key_i);




		if (header->next == nullptr) {
			new_elem->next = new_elem;
			header->next = new_elem;
			header->data++;
			return;
		}

		first = header->next->next;

		if (new_elem->data > header->next->data) {
			new_elem->next = first;
			header->next->next = new_elem;
			header->next = new_elem;
			header->data++;
			return;
		}

		current = first;
		previous = header->next;
		while (current->data < new_elem->data) {
			current = current->next;
			previous = previous->next;
		}
		if (current->data == new_elem->data)return;
		previous->next = new_elem;
		new_elem->next = current;
		header->data++;

	}


	void delete_elem(long long key_d)override {
		Elem* current = header->next->next;
		Elem* previous = header->next;
		long long i = header->data;

		if (header->data == 0) return; // First element. Ovde bi mogao izuzetak.
		if (header->data == 1)
			if (key_d == header->next->data) {
				delete current;
				header->data--;
			}

		while (i-- && current->data < key_d) {
			current = current->next;
			previous = previous->next;
		}
		if (current->data == key_d) {
			if (current->data == header->next->data) {   // Last element.
				previous->next = header->next->next;
				header->next = previous;
				delete current;
				header->data--;
			}
			else {
				previous->next = current->next;
				delete current;
				header->data--;
			}
		}
	}

	void delete_elem_scope(long long a, long long b) override {
		Elem* begin, * end, * previous_end, * previous_begin, * erase = NULL;
		bool erased = false;

		if (a > b)return; // Stavi izuzetak. Neispravno zadat interval.
						  // Izuzetak ako je a ili b cvor koji ne postoji.

		begin = header->next->next;
		previous_begin = previous_end = header->next;


		while (begin->data != a && a != b) {
			begin = begin->next;
			previous_begin = previous_begin->next;
		}
		end = begin;
		previous_end = previous_begin;
		while (end->data != b) {
			end = end->next;
			previous_end = previous_end->next;
		}

		if (a == header->next->next->data && a != b && !erased) { //Begin of list. a razl od b
			header->next->next = end->next;
			while (begin != end) {
				erase = begin;
				begin = begin->next;
				delete erase;
				header->data--;

			}
			if (begin == end) {
				delete begin;
				header->data--;
			}


			erased = true;


		}


		if (end == header->next && a != b && !erased) { // End of list. a razl od b
			previous_begin->next = header->next->next;
			header->next = previous_begin;
			while (begin != end) {
				erase = begin;
				begin = begin->next;
				delete erase;
				header->data--;
			}
			if (begin == end) {
				delete end;
				header->data--;
			}
			erased = true;

		}

		if (a != header->next->next->data && b != header->next->data && !erased) {
			previous_begin->next = end->next;
			while (begin != end) {
				erase = begin;
				begin = begin->next;
				delete erase;
				header->data--;
			}
			if (begin == end) {
				delete end;
				header->data--;
			}
			erased = true;
		}

		if (a == b && !erase) {
			previous_end->next = end->next;
			delete end;
			header->data--;
			erased = true;
		}








	}

	long long number_elem()const override {
		return header->data;
	}

	void difference(List& l1, List& l2) {
		//delete this;


		Elem* current1 = l1.header->next->next;
		Elem* current2 = l2.header->next->next;
		Elem* current3;


		long long i = l1.header->data;
		long long j = l2.header->data;


		while (i > 0 && j > 0) {
			if (current1->data != current2->data) {
				if (current1->data < current2->data) {
					insert_elem(current1->data);
					current1 = current1->next;
					i--;
				}
				else { // if (current1->data > current2->data)
					while (current1->data > current2->data) {
						//insert_elem(current2->data);
						current2 = current2->next;
						j--;
					}
				}
			}
			else {
				current1 = current1->next;
				current2 = current2->next;
				i--;
				j--;
			}

		}

		if (j == 0) {
			while (i > 0) {
				insert_elem(current1->data);
				current1 = current1->next;
				i--;
			}
		}

		// Writing on standard output.
		if (header->data == 0) {
			cout << "Emty set." << endl;
			return;
		}
		current3 = header->next->next;
		cout << "Difference: ";



		while (this->header->data--) {

			cout << " " << current3->data;
			current3 = current3->next;

		}





	}

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

	void ispisi() {

		Elem* current;
		long long i = header->data;
		if (i == 0) {
			cout << "List is empty." << endl;
			return;
		}
		current = header->next->next;

		while (i--) {
			std::cout << current->data;
			current = current->next;
		}
		puts("");
		std::cout << "Number of elements: " << number_elem() << endl;
	}



	void delete_set() {
		if (header->next == nullptr) return;
		Elem* current = header->next->next;
		Elem* old;
		long long i = header->data;
		while (i--) {
			old = current;
			current = current->next;
			delete old;
		}
		header->data = 0;
		header->next = nullptr;

	}


};

