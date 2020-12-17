/*
 * main.cpp
 *
 *  Created on: Dec 2, 2020
 *      Author: francisco
 */

#include "binaryTree.h"

int main(){

	BinTree<int> prueba;

	prueba.addValue(10);
	prueba.addValue(2);
	prueba.addValue(90);
	prueba.addValue(50);
	prueba.addValue(5);
	prueba.addValue(3);
	prueba.addValue(76);
	prueba.addValue(100);
	prueba.addValue(95);
	prueba.addValue(97);
	prueba.addValue(96);
	prueba.addValue(98);

	cout << prueba.inTree(50) << endl;
	cout << prueba.inTree(1) << endl;
	cout << prueba.getMax() << endl;
	cout << prueba.getMin() << endl;
	cout << prueba.getSuccessor(90) << endl;
	cout << prueba.getPredeccessor(90) << endl;

	prueba.erase(90);

	prueba.inOrderWalk();

	return 0;
}


