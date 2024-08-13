#pragma once
#include<iostream>
using namespace std;


void result(long double matrix1[5][6], long double matrix2[5][6]) {


	cout << "********************************PERFORMANCE FOR SET IMPLEMENTED LIKE TREE********************************" << endl;

	cout << "SIZE OF SET            200               500                | 1000              |10000              |100000" << endl;



	for (int i = 0; i < 5; i++) {
		if (i == 0)cout << "FORMING  ";
		if (i == 1)cout << "INSERTION  ";
		if (i == 2)cout << "DELETING  ";
		if (i == 3)cout << "SEARCHING  ";
		if (i == 4)cout << "DIFFERENCING  ";
		for (int j = 0; j < 6; j++) {
			if (i == 0) {

				cout << matrix1[i][j] << " ";

			}

			if (i == 1) {

				cout << matrix1[i][j] << " ";

			}

			if (i == 2) {

				cout << matrix1[i][j] << " ";

			}

			if (i == 3) {

				cout << matrix1[i][j] << " ";

			}

			if (i == 4) {

				cout << matrix1[i][j] << " ";

			}

		}
		cout << endl;
	}





	cout << "***************************PERFORMANCE FOR SET IMPLEMENTED LIKE CIRCULAR SINGLE LINKED LIST***************************" << endl;

	cout << "SIZE OF SET            |200               |500                 |10000              |100000" << endl;



	for (int i = 0; i < 5; i++) {
		if (i == 0)cout << "FORMING  ";
		if (i == 1)cout << "INSERTION  ";
		if (i == 2)cout << "DELETING  ";
		if (i == 3)cout << "SEARCHING  ";
		if (i == 4)cout << "DIFFERENCING  ";
		for (int j = 0; j < 6; j++) {
			if (i == 0) {

				cout << matrix2[i][j] << " ";

			}

			if (i == 1) {

				cout << matrix2[i][j] << " ";

			}

			if (i == 2) {

				cout << matrix2[i][j] << " ";

			}

			if (i == 3) {

				cout << matrix2[i][j] << " ";

			}

			if (i == 4) {

				cout << matrix2[i][j] << " ";

			}

		}
		cout << endl;
	}



}