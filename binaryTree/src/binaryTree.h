/*
 * binaryTree.h
 *
 *  Created on: Dec 2, 2020
 *      Author: francisco
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#ifndef TREENODE
#define TREENODE
#include "treeNode.h"
#endif

#ifndef STRING
#define STRING
#include <string>
using std::string;
#endif

#ifndef CONSOLE
#define CONSOLE
#include <iostream>
using std::cout;
using std::endl;
#endif

template <class Type> class BinTree{

private:

	TreeNode<Type>* root;

	TreeNode<Type>* pointer;

	/*
	 * Pre: El pointer tiene
	 * que apuntar a un nodo que tenga
	 * el espacio disponible
	 * Post: coloca al nuevo
	 * valor en el puntero
	 * correspondiente
	 */
	void setInPlace(Type value);

	/*
	 * Post: Realiza la caminata en orden
	 */
	void inOrder(TreeNode<Type>* actual);

	/*
	 * Post: Libera la memoria de ese nodo
	 */
	void deleteWalk(TreeNode<Type>* actual);

	/*
	 * Post: Devuelve si el elemento
	 * se encuentra en el arbol
	 */
	TreeNode<Type>* inTree(TreeNode<Type>* parser, Type value);

	/*
	 * Post: levanta una excepcion
	 * si el arbol esta vacio
	 */
	void raiseEmpty();


	/*
	 * Pre: El subarbol no debe estar vacio
	 * Post: Devuelve un puntero al nodo maximo
	 * de un subarbol particular
	 */
	TreeNode<Type>* getMax(TreeNode<Type>* subRoot);

	/*
	 * pre: El subarbol no debe estar vacio
	 * Post: Devuelve un puntero al nodo minimo de
	 * un subarbol en particular
	 */
	TreeNode<Type>* getMin(TreeNode<Type>* subRoot);

	/*
	 * Pre: El valor debe estar en el arbol
	 * Post: Devuelve un puntero al sucesor
	 * del valor pasado como parametro
	 */
	TreeNode<Type>* findSuccessor(TreeNode<Type>* node);

	/*
	 * Pre: El valor debe estar en el
	 * arbol
	 * Post: Devuelve un puntero al
	 * predecesor del valor pasado
	 * como parametro
	 */
	TreeNode<Type>* findPredeccessor(TreeNode<Type>* node);

	/*
	 * Pre: EL nodo no debe tener hijos
	 * Post: Elimina del arbol a ese nodo
	 */
	void eraseNoChilds(TreeNode<Type>* node);

	/*
	 * Pre: EL nodo debe tener unicamente un solo
	 * hijo
	 * Post: Elimina al nodo del arbol
	 */
	void eraseOneChild(TreeNode<Type>* node);

	/*
	 * Pre: El nodo debe tener dos hijos
	 * Post: Elimina al nodo del arbol
	 */
	void eraseTwoChilds(TreeNode<Type>* node);

public:

	/*
	 * Post: Inicializa un ABB
	 * con un valor en root
	 */
	BinTree(Type value);

	/*
	 * Post: Inicializa un ABB
	 * vacio
	 */
	BinTree();

	/*
	 * Post: ---
	 */
	~BinTree();

	/*
	 * Pre: El valor debe estar incluido
	 * en el arbol
	 * Post: Elimina al valor del arbol
	 */
	void erase(Type value);

	/*
	 * Post: Agrega un valor al
	 * arbol binario
	 */
	void addValue(Type value);

	/*
	* Post: Hace la caminata
	* en orden del arbol
	*/
	void inOrderWalk();

	/*
	 * Post: Devuelve si el elemento
	 * se encuentra en el arbol
	 */
	bool inTree(Type value);

	/*
	 * Pre: El arbol debe tener al menos
	 * un elemento
	 * Post: Devuelve el maximo del arbol
	 */
	Type getMax();

	/*
	 * Pre: El arbol debe tener al menos un
	 * elemento
	 * Post: Devuelve el minimo del arbol
	 */
	Type getMin();

	/*
	 * pre: El valor debe estar
	 * en el arbol
	 * Post: Devuelve el siguiente
	 * mas grande al elemento pasado
	 * como parametro.Si el elemento es
	 * el mayor, devuelve 0
	 */
	Type getSuccessor(Type value);

	/*
	 * Pre: El valor debe estar en el arbol
	 * Post: Devuelve el anterior al valor
	 * pasado como parametro
	 */
	Type getPredeccessor(Type value);
};


template <class Type>
BinTree<Type>::BinTree(){

	root = NULL;

	pointer = NULL;
}

template <class Type>
BinTree<Type>::BinTree(Type value){

	root = new TreeNode<Type>(value);

	pointer = NULL;

}


template <class Type>
BinTree<Type>::~BinTree(){
	pointer = root;

	deleteWalk(pointer);

}

template <class Type>
void BinTree<Type>::addValue(Type value){

	if(!root){
		root = new TreeNode<Type>(value);
	}
	else{
		pointer = root;

		TreeNode<Type>* aux = pointer;

		while((aux = aux->getNext(value))
				&& pointer != aux){
			pointer = aux;
		}

		if(pointer != aux){

			setInPlace(value);

		}

	}

}

template <class Type>
void BinTree<Type>::inOrderWalk(){

	pointer = root;
	inOrder(pointer);
	cout << endl;

}

template <class Type>
bool BinTree<Type>::inTree(Type value){

	return inTree(root, value);

}

template <class Type>
Type BinTree<Type>::getMax(){

	raiseEmpty();

	pointer = root;

	return getMax(pointer)->getKey();
}

template <class Type>
Type BinTree<Type>::getMin(){

	raiseEmpty();

	pointer = root;

	return getMin(pointer)->getKey();
}

template <class Type>
Type BinTree<Type>::getSuccessor(Type value){


	if (!(pointer = inTree(root, value))){
		throw string("NOT IN TREE");
	}

	TreeNode<Type>* successor = findSuccessor(pointer);


	return successor ? successor->getKey(): NULL;

}

template <class Type>
Type BinTree<Type>::getPredeccessor(Type value){

	if (!(pointer = inTree(root, value))){
		throw string("NOT IN TREE");
	}
	TreeNode<Type>* predeccessor = findPredeccessor(pointer);


	return predeccessor ? predeccessor->getKey(): NULL;
}

template <class Type>
void BinTree<Type>::erase(Type value){
	if(!(pointer = inTree(root, value))){
		throw string("NOT IN TREE");
	}
	switch(pointer->childNodes()){

	case 0: eraseNoChilds(pointer);
		break;
	case 1: eraseOneChild(pointer);
		break;
	case 2: eraseTwoChilds(pointer);
		break;
	}

}

/*
 * Metodos privados
 */
template <class Type>
void BinTree<Type>::setInPlace(Type value){

	TreeNode<Type>* newValue = \
			new TreeNode<Type>(value, this->pointer);

	if(value > this->pointer->getKey()){

		this->pointer->setRigth(newValue);

	}
	else{
		this->pointer->setLeft(newValue);
	}

}

template <class Type>
void BinTree<Type>::inOrder(TreeNode<Type>* actual){

	if(actual){

		inOrder(actual->getLeft());

		cout << actual->getKey() << "--";

		inOrder(actual->getRigth());

	}

}


template <class Type>
void BinTree<Type>::deleteWalk(TreeNode<Type>* actual){

	if(actual){
		deleteWalk(actual->getLeft());
		deleteWalk(actual->getRigth());
		delete actual;
	}

}

template <class Type>
TreeNode<Type>* BinTree<Type>::inTree(TreeNode<Type>* parser, Type value){

	if(!parser){
		return NULL;
	}
	else if(parser->getKey() == value){
		return parser;
	}
	else {
		return inTree(parser->getNext(value), value);
	}
}

template <class Type>
void BinTree<Type>::raiseEmpty(){

	if(!root){
		throw string("EMPTY TREE");
	}
}

template <class Type>
TreeNode<Type>* BinTree<Type>::getMax(TreeNode<Type>* subRoot){
	pointer = subRoot;

	while(pointer->getRigth()){
		pointer = pointer->getRigth();
	}

	return pointer;
}

template <class Type>
TreeNode<Type>* BinTree<Type>::getMin(TreeNode<Type>* subRoot){
	pointer = subRoot;

	while(pointer->getLeft()){
		pointer = pointer->getLeft();
	}

	return pointer;
}

template <class Type>
void BinTree<Type>::eraseNoChilds(TreeNode<Type>* node){
	TreeNode<Type>* parent = node->getParent();

	if (node == parent->getLeft()){
		parent->setLeft(NULL);
	}
	else{
		parent->setRigth(NULL);
	}

}

template <class Type>
void BinTree<Type>::eraseOneChild(TreeNode<Type>* node){

	TreeNode<Type>* aux = node;
	TreeNode<Type>* parent = node->getParent();

	node = (node->getLeft() ? node->getLeft() :
					node->getRigth());

	if (aux == parent->getLeft()){

		parent->setLeft(node);
	}
	else{
		parent->setRigth(node);
	}

	delete aux;

}

template <class Type>
void BinTree<Type>::eraseTwoChilds(TreeNode<Type>* node){

	TreeNode<Type>* successor = findSuccessor(node);

	/*
	 * Caso no es el hijo derecho del nodo
	 */
	if (!(successor == node->getRigth())){
		successor->getParent()->setLeft(successor->getRigth());\
		successor->setRigth(successor->getParent());

	}
	successor->setLeft(node->getLeft());
	/*
	 * Si el que elimino es un hijo izquierdo
	 */
	if(node == node->getParent()->getLeft()){
		node->getParent()->setLeft(successor);
	}
	/*
	 * Si es un hijo derecho
	 */
	else{
		node->getParent()->setRigth(successor);
	}

	successor->getLeft()->setParent(successor);

	delete node;

}

template <class Type>
TreeNode<Type>* BinTree<Type>::findSuccessor(TreeNode<Type>* value){
	TreeNode<Type>* successor = pointer;
	if (pointer->getRigth()){

			successor = getMin(pointer->getRigth());
	}
	else{
		TreeNode<Type>* aux = pointer->getParent();

		while (aux && aux->getRigth() == successor){
			successor = aux;

			aux = aux->getParent();
		}
		successor = aux;

	}

	return successor;
}

template <class Type>
TreeNode<Type>* BinTree<Type>::findPredeccessor(TreeNode<Type>* node){
	TreeNode<Type>* predeccessor = pointer;

	if (pointer->getLeft()){

		predeccessor = getMax(pointer->getLeft());
	}
	else{

		TreeNode<Type>* aux = pointer->getParent();

		while (aux && aux->getLeft() == predeccessor){
			predeccessor = aux;

			aux = aux->getParent();
		}
		predeccessor = aux;

	}

	return predeccessor;
}

#endif /* BINARYTREE_H_ */
