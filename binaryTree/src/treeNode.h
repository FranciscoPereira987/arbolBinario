/*
 * treeNode.h
 *
 *  Created on: Dec 2, 2020
 *      Author: francisco
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#ifndef NULL
#define NULL 0
#endif

#ifndef SONTYPE
#define SONTYPE
enum SonType{

	RIGTH = 0,
	LEFT

};
#endif


template <class Type> class TreeNode{

private:

	Type key;

	TreeNode* father;

	TreeNode* left;

	TreeNode* rigth;


	/*
	 * Post: Cambia el valor de uno
	 * de sus hijos
	 * si el valor es verdadero, cambia
	 * el valor de su hijo izquierdo
	 * si no cambia el derecho
	 */
	void setSon(TreeNode* newSon, bool leftSon);


public:

	/*
	 * Post: Se crea un nodo
	 * sin padre pero con una
	 * clave
	 */
	TreeNode(Type value);

	/*
	 * Post: Se crea un nodo con
	 * padre y valor
	 */
	TreeNode(Type value, TreeNode*& parent);

	/*
	 * Post: cambia el valor de
	 * su hijo izquierdo
	 */
	void setLeft(TreeNode* newLeft);

	/*
	 * Post: cambia el valor de su
	 * hijo derecho
	 */
	void setRigth(TreeNode* newRigth);

	/*
	 * Post: Cambia el valor de su padre
	 */
	void setParent(TreeNode* newParent);

	/*
	 * Post: Devuelve la cantida de
	 * hijos de un nodo
	 */
	char childNodes();

	/*
	 * Post: Devuelve el siguiente nodo
	 * segun el valor pasado como parametro
	 * si es igual, devuelve la direccion de si mismo
	 */
	TreeNode* getNext(Type value);

	/*
	 * Post: devuelve el valor
	 * del padre
	 */
	TreeNode* getParent();

	/*
	 * Post: Devuelve el valor
	 * de la llave
	 */
	Type getKey();


	/*
	 * Post: devuelve el valor de la izquierda
	 */
	TreeNode* getLeft();

	/*
	 * Post: Devuelve el valor de la derecha
	 */
	TreeNode* getRigth();


};

template <class Type>
TreeNode<Type>::TreeNode(Type value){

	this->key = value;

	this->father = this->left = this->rigth = NULL;

}

template <class Type>
TreeNode<Type>::TreeNode(Type value, TreeNode*& parent){

	this->key = value;

	this->father = parent;

	this->left = this->rigth = NULL;

}

template <class Type>
char TreeNode<Type>::childNodes(){

	bool leftSon = this->left,
			rigthSon = this->rigth;

	char total = (char) leftSon + (char) rigthSon;

	return total;

}

template <class Type>
void TreeNode<Type>::setLeft(TreeNode* newLeft){

	this->setSon(newLeft, LEFT);

}

template <class Type>
void TreeNode<Type>::setRigth(TreeNode* newRigth){

	this->setSon(newRigth, RIGTH);
}


template <class Type>
TreeNode<Type>* TreeNode<Type>::getNext(Type value){
	TreeNode* next = this;

	if(value > this->key){
		next = this->rigth;
	}
	else if(value != this->key){
		next = this->left;
	}

	return next;

}

template <class Type>
TreeNode<Type>* TreeNode<Type>::getParent(){

	return this->father;
}

template <class Type>
Type TreeNode<Type>::getKey(){

	return this->key;
}

template <class Type>
TreeNode<Type>* TreeNode<Type>::getLeft(){

	return this->left;
}

template <class Type>
TreeNode<Type>* TreeNode<Type>::getRigth(){

	return this->rigth;
}

template <class Type>
void TreeNode<Type>::setParent(TreeNode* newParent){

	father = newParent;
}


/*
 * Metodos privados
 */
template <class Type>
void TreeNode<Type>::setSon(TreeNode* newSon, bool leftSon){

	if(leftSon){
		this->left = newSon;
	}
	else{
		this->rigth = newSon;
	}

}


#endif /* TREENODE_H_ */
