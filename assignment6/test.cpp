/*
 * test.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: Vincent
 */

#include "BinaryHeap.h"

using namespace std;
using namespace ods;

int main() {
	srand(NULL);
	BinaryHeap<int> bh;
	for(int i = 0; i < 20; i++){
		int ran = rand();
		bh.add(ran % 100);
	}
	bh.print();
	for(int i = 0; i < 10; i++){
		int ran = rand() % bh.size();
		bh.remove(ran);
		cout << ran << "     "<< endl;
		bh.print();
		cout << endl;
	}
	bh.print();
	return 0;
}


