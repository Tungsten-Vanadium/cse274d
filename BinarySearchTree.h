/*
 * BinarySearchTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include "BinaryTree.h"
#include "utils.h"

namespace ods {

template<class Node, class T>
class BSTNode : public BTNode<Node> {
public:
	T x;

	// Implemented fields
	int pre_number;
	int in_number;
	int post_number;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree : public BinaryTree<Node> {
protected:
	using BinaryTree<Node>::r;
	using BinaryTree<Node>::nil;
	int n;
	T null;

	virtual Node *findLast(T x);
	virtual bool addChild(Node *p, Node *u);
	virtual void splice(Node *u);
	virtual void remove(Node *u);
	virtual void rotateRight(Node *u);
	virtual void rotateLeft(Node *u);
	virtual bool add(Node *u);
public:
	BinarySearchTree();
	BinarySearchTree(T null);
	virtual ~BinarySearchTree();
	virtual bool add(T x);
	virtual bool remove(T x);
	virtual T find(T x);
	virtual T findEQ(T x);
	virtual int size();
	virtual void clear();

	// Implemented methods
	void preOrderNumber();
	int preOrderNumber(Node* u, int* c);
	void inOrderNumber();
	int inOrderNumber(Node* u, int* c);
	void postOrderNumber();
	int postOrderNumber(Node* u, int* c);
	Node* getNode(T x);
};

template<class T>
class BSTNode1 : public BSTNode<BSTNode1<T>, T> { };

template<class T>
class BinarySearchTree1 : public BinarySearchTree<BSTNode1<T>, T> {
public:
	BinarySearchTree1();
};


/*
 * FIXME: Why doesn't this work?
template<class Node>
BinarySearchTree<Node,int>::BinarySearchTree()  {
	this->null = INT_MIN;
	n = 0;
}
*/

template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree() {
	this->null = (T)NULL;  // won't work for non-primitive types
	n = 0;
}


template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree(T null) {
	this->null = null;
	n = 0;
}

template<class Node, class T>
Node* BinarySearchTree<Node,T>::findLast(T x) {
	Node *w = r, *prev = nil;
	while (w != nil) {
		prev = w;
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return prev;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::findEQ(T x) {
	Node *w = r;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return null;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::find(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return z == nil ? null : z->x;
}

template<class Node, class T>
BinarySearchTree<Node,T>::~BinarySearchTree() {
	// nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
		if (p == nil) {
			r = u;              // inserting into empty tree
		} else {
			int comp = compare(u->x, p->x);
			if (comp < 0) {
				p->left = u;
			} else if (comp > 0) {
				p->right = u;
			} else {
				return false;   // u.x is already in the tree
			}
			u->parent = p;
		}
		n++;
		return true;
	}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
	Node *p = findLast(x);
	Node *u = new Node;
	u->x = x;
	return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
	Node *p = findLast(u->x);
	return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
	Node *s, *p;
	if (u->left != nil) {
		s = u->left;
	} else {
		s = u->right;
	}
	if (u == r) {
		r = s;
		p = nil;
	} else {
		p = u->parent;
		if (p->left == u) {
			p->left = s;
		} else {
			p->right = s;
		}
	}
	if (s != nil) {
		s->parent = p;
	}
	n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
	if (u->left == nil || u->right == nil) {
		splice(u);
		delete u;
	} else {
		Node *w = u->right;
		while (w->left != nil)
			w = w->left;
		u->x = w->x;
		splice(w);
		delete w;
	}
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
	Node *u = findLast(x);
	if (u != nil && compare(x, u->x) == 0) {
		remove(u);
		return true;
	}
	return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
	return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
	BinaryTree<Node>::clear();
	n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
	Node *w = u->right;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->right = w->left;
	if (u->right != nil) {
		u->right->parent = u;
	}
	u->parent = w;
	w->left = u;
	if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
	Node *w = u->left;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->left = w->right;
	if (u->left != nil) {
		u->left->parent = u;
	}
	u->parent = w;
	w->right = u;
	if (u == r) { r = w; r->parent = nil; }
}



/*
template<class T>
BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
}
*/

template<class T>
BinarySearchTree1<T>::BinarySearchTree1()  {
}

// Implemented for Part 3
template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber() {
	int b = 0;
	int* c = &b;
	preOrderNumber(r, c);
}

template<class Node, class T>
int BinarySearchTree<Node, T>::preOrderNumber(Node* u, int* c){
	if(u == nil) return *c;
	int b = *c;
	u->pre_number = b;
	b++;
	//std::cout<<b<<"     ";
	b = preOrderNumber(u->left, &b);
	return preOrderNumber(u->right, &b);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber() {
	int b = 0;
	int* c = &b;
	inOrderNumber(r, c);
}

template<class Node, class T>
int BinarySearchTree<Node, T>::inOrderNumber(Node* u, int* c){
	if(u == nil) return *c;
	int b = *c;
	b = inOrderNumber(u->left, &b);
	u->in_number = b;
	b++;
	return inOrderNumber(u->right, &b);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumber() {
	//int size = this->size() - 1;
	int b = 0;
	int* c = &b;//&size;
	postOrderNumber(r, c);
}

template<class Node, class T>
int BinarySearchTree<Node, T>::postOrderNumber(Node* u, int* c){
	if(u == nil) return *c;
	int b = *c;
	/*u->post_number = b;
	b--;
	b = postOrderNumber(u->right, &b);
	return postOrderNumber(u->left, &b);*/
	b = postOrderNumber(u->left, &b);
	b = postOrderNumber(u->right, &b);
	u->post_number = b;
	b++;
	return b;
}

template<class Node, class T>
Node* BinarySearchTree<Node, T>::getNode(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return z == nil ? nil : z;
}

} /* namespace ods */
#endif /* BINARYSEARCHTREE_H_ */
