#pragma once
#include "Performance_Calculator.h"
#include "Tree.h"
#include "List.h"


// Perofemance for linked list and sets

void claculate_performance(long double matrix1[5][6], long double matrix2[5][6], long long i, int index) {

	int counter = 3;
	PerformanceCalculator pfc_calc1;  // For start.
	Tree tree, tree1, tree2;
	List list, list1, list2;
	long long elem;


	while (counter > 0) {
		counter--;
		list.delete_set();
		tree.delete_tree();

		while (list.number_elem() < i) {
			elem = rand() * (RAND_MAX + 1) + rand();
			//PERFORMANCE FOR FORMING


			pfc_calc1.start();
			tree.insert_elem(elem);
			pfc_calc1.stop();
			matrix1[index][0] += pfc_calc1.elapsedMillis();

			pfc_calc1.start();
			list.insert_elem(elem);
			pfc_calc1.stop();
			matrix2[index][0] += pfc_calc1.elapsedMillis();
		}


		//PERFORMANCE FOR INSERTION
		elem = rand() * (RAND_MAX + 1) + rand();

		pfc_calc1.start();
		tree.insert_elem(elem);
		pfc_calc1.stop();
		matrix1[index][1] += pfc_calc1.elapsedMillis();

		pfc_calc1.start();
		list.insert_elem(elem);
		pfc_calc1.stop();
		matrix2[index][1] += pfc_calc1.elapsedMillis();

		//PERFORMANCE FOR DELETING
		elem = rand() * (RAND_MAX + 1) + rand();

		pfc_calc1.start();
		tree.delete_elem(elem);
		pfc_calc1.stop();
		matrix1[index][2] += pfc_calc1.elapsedMillis();

		pfc_calc1.start();
		list.delete_elem(elem);
		pfc_calc1.stop();
		matrix2[index][2] += pfc_calc1.elapsedMillis();


		//PERFORMANCE FOR SEARCHING

		elem = rand() * (RAND_MAX + 1) + rand();

		pfc_calc1.start();
		tree.search_elem(elem);
		pfc_calc1.stop();
		matrix1[index][3] += pfc_calc1.elapsedMillis();

		pfc_calc1.start();
		list.search_elem(elem);
		pfc_calc1.stop();
		matrix2[index][3] += pfc_calc1.elapsedMillis();


		//PERFORMANCE FOR OPERATION (DIFFERENCE)


		/*		if (list1.number_elem() != 0)*/list1.delete_set();
		/*			if (tree1.number_elem() != 0)*/tree1.delete_tree();

		while (list1.number_elem() < i) {

			elem = rand() * (RAND_MAX + 1) + rand();
			list1.insert_elem(elem);
			tree1.insert_elem(elem);
		}
		/*if (list2.number_elem() != 0)*/list2.delete_set();
		/*		if (tree2.number_elem() != 0)*/tree2.delete_tree();


		pfc_calc1.start();
		tree2.difference_trre(tree, tree1);
		pfc_calc1.stop();
		matrix1[index][4] += pfc_calc1.elapsedMillis();

		pfc_calc1.start();
		list2.difference(list, list1);
		pfc_calc1.stop();
		matrix2[index][4] += pfc_calc1.elapsedMillis();


	}

	for (int i = 0; i < 4; i++) {
		matrix1[index][i] /= 3;
		matrix2[index][i] /= 3;
	}




};








