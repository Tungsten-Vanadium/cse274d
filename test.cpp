/*
 * test.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: Vincent
 */

#include <iostream>

#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace ods;

BinarySearchTree<BSTNode1<int>, int> treeMaker(int i){
	BinarySearchTree<BSTNode1<int>, int> tree;
	if(i == 1){
		tree.add(10);
		tree.add(5);
		tree.add(15);
		tree.add(3);
		tree.add(0);
		tree.add(2);
	}else{
		tree.add(20);
		tree.add(10);
		tree.add(30);
		tree.add(5);
		tree.add(15);
		tree.add(25);
		tree.add(35);
	}
	return tree;
}

void testPart1(){
	BinarySearchTree<BSTNode1<int>, int> tree = treeMaker(1);
	BSTNode1<int>* node = tree.getNode(10);
	cout << tree.size() << endl;
	cout << tree.height() << endl;
	cout << tree.height2(node) << endl << endl;
	BinarySearchTree<BSTNode1<int>, int> tree2 = treeMaker(2);
	BSTNode1<int>* node2 = tree2.getNode(20);
	cout << tree2.size() << endl;
	cout << tree2.height() << endl;
	cout << tree2.height2(node2) << endl << "END1" << endl;
}

void testPart2(){
	BinarySearchTree<BSTNode1<int>, int> tree = treeMaker(1);
	cout << tree.isBalanced() << endl << endl;
	BinarySearchTree<BSTNode1<int>, int> tree2 = treeMaker(2);
	cout << tree2.isBalanced() << endl << "END2" << endl;
}

void testPart3(){
	BinarySearchTree<BSTNode1<int>, int> tree = treeMaker(1);
	BinarySearchTree<BSTNode1<int>, int> tree2 = treeMaker(2);
	tree.preOrderNumber();
	cout << tree.getNode(10)->pre_number << endl;
	cout << tree.getNode(15)->pre_number << endl;
	cout << tree.getNode(2)->pre_number << endl << endl;

	tree.inOrderNumber();
	cout << tree.getNode(10)->in_number << endl;
	cout << tree.getNode(15)->in_number << endl;
	cout << tree.getNode(2)->in_number << endl << endl;

	tree.postOrderNumber();
	cout << tree.getNode(10)->post_number << endl;
	cout << tree.getNode(15)->post_number << endl;
	cout << tree.getNode(2)->post_number << endl << endl;

	tree2.preOrderNumber();
	cout << tree2.getNode(20)->pre_number << endl;
	cout << tree2.getNode(5)->pre_number << endl;
	cout << tree2.getNode(35)->pre_number << endl;
	cout << tree2.getNode(10)->pre_number << endl;
	cout << tree2.getNode(30)->pre_number << endl << endl;

	tree2.inOrderNumber();
	cout << tree2.getNode(20)->in_number << endl;
	cout << tree2.getNode(5)->in_number << endl;
	cout << tree2.getNode(35)->in_number << endl;
	cout << tree2.getNode(10)->in_number << endl;
	cout << tree2.getNode(30)->in_number << endl << endl;

	tree2.postOrderNumber();
	cout << tree2.getNode(20)->post_number << endl;
	cout << tree2.getNode(5)->post_number << endl;
	cout << tree2.getNode(35)->post_number << endl;
	cout << tree2.getNode(10)->post_number << endl;
	cout << tree2.getNode(30)->post_number << endl << "END3" << endl;
}

void testPart4(){
	BinarySearchTree<BSTNode1<int>, int> tree = treeMaker(1);
	// Created print method in DLList
	tree.getLE(5).print();
	tree.getLE(30).print();
	tree.getLE(-1).print();
	cout << endl;
	BinarySearchTree<BSTNode1<int>, int> tree2 = treeMaker(2);
	tree2.getLE(50).print();
	tree2.getLE(20).print();
	tree2.getLE(0).print();
	cout << "END4" << endl;
}

int main(){
	testPart1();
	testPart2();
	testPart3();
	testPart4();
}
