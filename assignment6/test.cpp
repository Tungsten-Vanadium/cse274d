/*
 * test.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: Vincent
 */

#include "BinaryHeap.h"
#include <stdlib.h>

using namespace std;
using namespace ods;

int main() {
	srand(NULL);
	BinaryHeap<int> bh;
	for(int i = 0; i < 3000; i++){
		bh.add(rand());
	}
	//bh.print();
	cout << bh.checkHeap() << endl;
	for(int i = 0; i < 3000; i++){
		int ran = rand() % bh.size();
		bh.remove(ran);
		if(!bh.checkHeap()){
			cout << "ERROR";
			return 1;
		}
	}
	cout << "Done";
	return 0;
}


