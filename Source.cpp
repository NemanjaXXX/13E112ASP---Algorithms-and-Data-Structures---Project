#include<iostream>
#include"List.h"
#include"Tree.h"
#include"Performance_Calculator.h"
#include"Performance_Calculator_Function.h"
#include"Result_Of_Performance.h"
#include"Security.h"
using namespace std;



int main() {


	int choice; // for list=1 of tree=2
	int file;
	int operation;
	int key;
	int end = 0;
	int number;
	Tree tree;
	Tree tree2;
	Tree tree3;
	List list;
	List list2;
	List list3;

	long double matrix1[5][6] = { 0 };  //Tree
	long double matrix2[5][6] = { 0 }; //List

	long long i;



	cout << "                               WELCOME" << endl;
	cout << "                       IMPLEMENTATION OF SETS" << endl;
	puts("");

	cout << "What kind of set implemetation do you want to process?" << endl;
	cout << "Please, enter key 1 for list or key 2 for tree." << endl;
	cout << "Your choice: ";

	//PREVENTION OF INCORRECT INPUT
	cin >> input(choice);
	puts("");
	while (!cin || (choice != 1 && choice != 2)) {
		cin.clear();
		cout << "You entered wrong key!!!" << endl;
		cout << "Please, repeat your choice." << endl;
		cout << "Your choice: ";
		cin >> input(choice);
		puts("");
	}


	//PREVENTION OF INCORRECT INPUT
	cout << "Do you want process file? 1-YES 0-NO" << endl;
	cout << "IMPORTANT INSTRUCTION: If you want to process file, name of file must be input.txt and it must be in folder where is file Source.cpp." << endl;
	cout << "Your choice: ";
	cin >> input(file);
	puts("");
	while (!cin || (file != 0 && file != 1)) {
		cin.clear();
		cout << "You entered wrong key!!!" << endl;
		cout << "Please, repeat your choice." << endl;
		cout << "Your choice: ";
		cin >> input(file);
		puts("");
	}


	while (!end) {

		cout << "Please, choose operation which you want by the entering serial number from menu." << endl;
		puts("");
		cout << "MENU:";
		puts("");

		cout << "1. Insert element in set." << endl;
		cout << "2. Search element (determination of affiliation)." << endl;
		cout << "3. Delete element from set." << endl;
		cout << "4. Delete elements from set in scope ([a,b])." << endl;
		cout << "5. Number of elements in set." << endl;
		cout << "6. Difference between two sets." << endl;
		cout << "7. Create empty set." << endl;
		cout << "8. Destroy set." << endl;
		puts("");


		//PREVENTION OF INCORRECT INPUT
		cout << "Your choice: ";
		cin >> operation;
		puts("");
		while (!cin || (operation < 1 || operation > 8)) {
			cin.clear();
			cout << "You entered wrong key!!!" << endl;
			cout << "Please, repeat your choice." << endl;
			cout << "Your choice: ";
			cin >> input(operation);
			puts("");
		}


		switch (operation) { // Default is not necesserry.

		case 1:
			cout << "                  INSERT ELEMENT IN SET" << endl;
			puts("");

			if (file == 1) { // User want to process file.
				if (choice == 1) { // List.
					list.reading_file(); // uradi proveru ako su u datoteci carovi da iskoci
					cout << "End of loading. Your elements are successfuly inserted in set." << endl;
					break;
				}
				else { //Tree.
					tree.reading_file();
					cout << "End of loading. Your elements are successfuly inserted in set." << endl;
				}
			}
			else { // Enter elements from standard input.
				cout << "Please, enter the number of elements in this set: ";
				cin >> number;

				while (number <= 0) {
					cout << "Please, enter correct value." << endl;
					cout << "New value: ";
					cin >> number;
				}

				cout << "Please, enter the key(s) of element(s) which you want to insert in set." << endl;
				cout << "Elements (keys): ";

				while (number--) {
					cin >> key;
					if (choice == 1) list.insert_elem(key);
					if (choice == 2)tree.insert_elem(key);

				}



			}
			break;

		case 2:
			cout << "                  SEARCH ELEMENT (DETERMINATION OF AFFILIATION)" << endl;
			puts("");

			if (choice == 1) { // List.
				cout << "Please, eneter the key of element for which you want to know affiliation in list. " << endl;
				cout << "Key: ";
				cin >> key;

				if (list.search_elem(key)) {
					cout << "Element which key is " << key << " exists in list." << endl;
					puts("");
				}
				else {
					cout << "Element which key is not " << key << " exists in list." << endl;
					puts("");
				}

			}

			else {// choice=2 Tree.
				cout << "Please, eneter the key of element for which you want to know affiliation in tree. ";

				//PREVENTION OF INCORRECT INPUT
				cout << "Key of element: ";
				cin >> key;

				if (tree.search_elem(key)) {
					cout << "Element which key is " << key << "exists in list." << endl;
					puts("");
				}
				else {
					cout << "Element which key is not" << key << "exists in list." << endl;
					puts("");
				}

			}



			break;

		case 3:
			cout << "                  DELETE ELEMENT FROM SET" << endl;
			puts("");


			if (choice == 1) {// List.
				cout << "Please, enter the key of element which you want to delete from list. " << endl;
				cout << "Key:";
				cin >> key;
				if (list.search_elem(key)) {
					list.delete_elem(key);
					cout << "Element which key is " << key << " is successfully deleted from list. " << endl;
				}
				else {
					cout << "Element which key is " << key << " is successfully deleted from tree." << endl;
					puts("");
				}
				puts("");


			}
			else {// choice=2 Tree.
				cout << "Please, enter the key of element which you want to delete from list." << endl;
				cin >> key;
				tree.delete_elem(key);
				cout << "Element which key is " << key << " is successfully deleted from tree." << endl;
				puts("");



			}

			break;



		case 4:
			cout << "                  DELETE ELEMENTS FROM SET IN SCOPE ([A,B])" << endl;
			puts("");


			if (choice == 1) { // List.
				cout << "Please, enter the parameters A and B. This parameters are borders of segment." << endl;

				//PREVENTION OF INCORRECT INPUT
				cout << "Parameters [a,b] " << endl;
				cout << "Please enter parametar a:";
				cin >> key; // A

				cout << "Please enter parametar b:";
				cin >> file; // B  Now, i am using file because file is not necessery to the end of proggramme. One variable less.
				puts("");



				while (key > file) {
					cout << "You entered wrong parameters!!!" << endl;
					cout << "Please, repeat your choice." << endl;
					cout << "Enter parametar a: ";
					cin >> key;
					cout << "Enter parametar b:";
					cin >> file;
					puts("");
				}


				list.delete_elem_scope(key, file);
				cout << "All elements from segment[" << key << "," << file << "] are successfully deleted from list." << endl;
				puts("");


			}
			else { //choice=2 Tree
				cout << "Please, enter the parameters A and B. This parameters are borders of segment." << endl;

				//PREVENTION OF INCORRECT INPUT
				cout << "Parameters [a,b]: ";
				cin >> key; // A
				cin >> file; // B  Now, i am using file because file is not necessery to the end of proggramme. One variable less.
				puts("");

				while (key > file) {
					cout << "You entered wrong parameters!!!" << endl;
					cout << "Please, repeat your choice." << endl;
					cout << "Your choice: ";
					cin >> key;
					cin >> file;
					puts("");
				}


				tree.delete_elem_scope(key, file);
				cout << "All elements from segment[" << key << "," << file << "] are successfully deleted from tree." << endl;
				puts("");


			}




			break;


		case 5:

			cout << "                    NUMBER OF ELEMENTS IN SET" << endl;
			puts("");

			if (choice == 1) { // List.
				cout << "Number of elements in set is " << list.number_elem() << "." << endl;

			}
			else { //choice=2 Tree.
				cout << "Number of elements in set is " << tree.number_elem() << "." << endl;

			}



			break;

		case 6:
			cout << "                    DIFFERENCE BETWEEN TWO SETS" << endl;
			puts("");

			if (choice == 1) { //List.
				cout << "Please eneter the number of elements of second list: ";
				cin >> number;
				while (number <= 0) {
					cout << "You entered wrong value!!!" << endl;
					cout << "Please, repeat your choice. Number must be bigger than zero." << endl;
					cout << "Your choice: ";
					cin >> number;
					puts("");

				}
				cout << "Please, enter the keys: ";
				while (number--) {
					cin >> key;
					list2.insert_elem(key);
				}

				list3.difference(list, list2);


			}
			else { // choice=2 Tree.
				cout << "Please eneter the number of elements of second tree: ";
				cin >> number;
				while (number <= 0) {
					cout << "You entered wrong value!!!" << endl;
					cout << "Please, repeat your choice. Number must be bigger than zero." << endl;
					cout << "Your choice: ";
					cin >> number;
					puts("");

				}
				cout << "Please, enter the keys: ";
				while (number--) {
					cin >> key;
					tree2.insert_elem(key);
				}
				tree3.difference_trre(tree, tree2);
			}

			break;

		case 7:
			cout << "                    CREATE EMPTY SET" << endl;
			puts("");


			if (choice == 1) {//List.
				cout << "Empty set is successfuly created." << endl;
				puts("");
			}
			else {// choice=2 Tree.
				cout << "Empty set is successfuly created." << endl;
				puts("");
			}

			break;

		case 8:
			cout << "                    DESTROY ELEMENT FROM SET" << endl;
			puts("");

			if (choice == 1) {//List.
				if (list.number_elem())list.delete_set();
				cout << "All elements from list are successfuly deleted." << endl;
				puts("");


			}
			else {//choice=2 Tree.
				if (tree.number_elem())tree.delete_tree();
				cout << "All elements from list are successfuly deleted." << endl;
				puts("");
			}


			break;

		} // end of switch
		puts("");
		cout << "Do you want to end proggramme?" << endl;
		cout << "Please enter 1 for yes or 0 for no." << endl;

		cout << "Lista test: ";
		list.ispisi();
		puts("");

		//PREVENTION OF INCORRECT INPUT
		cout << "Your choice: ";
		cin >> end;
		puts("");
		while (end != 1 && end != 0) {
			cout << "You entered wrong key!!!" << endl;
			cout << "Please, repeat your choice." << endl;
			cout << "Your choice: ";
			cin >> end;
			puts("");
		}




	} // end of while

	/* ---RUN AS NEEDED---RUN AS NEEDED---RUN AS NEEDED---RUN AS NEEDED---RUN AS NEEDED---RUN AS NEEDED---

	// RESULT OF PERFORMANCE CALCULATOR
	//int index = 0;


		i = 5;
		claculate_performance(matrix1, matrix2, i, 0);
		//index++;


		i = 500;
		claculate_performance(matrix1, matrix2, i, 1);
	//	index++;


		i = 1000;
		claculate_performance(matrix1, matrix2, i, 2);
	//	index++;


		i = 10000;
		claculate_performance(matrix1, matrix2, i, 3);
	//	index++;


		//	i = 100000;
		//	claculate_performance(matrix1, matrix2, i,index);

			//i = 1000000;
			//claculate_performance(matrix1, matrix2, i, index);

			// TABEL FOR TREE

		cout << "***********************************RESULT OF PERFORMANCE CALCULATOR***********************************" << endl;
		puts("");

		result(matrix1, matrix2);



		cout << "Thank you for using this programme." << endl;
		puts("");





		

		cout << "br" <<endl ;
		cin >> number;
		int i1 = 0;
		if (i1++) cin.clear();
		cin >> input(number);
		while (!cin)
		{
			cin.clear();
			cout << "You have entered a non-existent option, please try again: ";
			cin >> input(number);
		}
		cout << "Entered value: " << number;

		
	system("pause");



	*/

}

