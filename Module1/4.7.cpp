#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "4.7 and 4.8.h"

using namespace std;

int main3() {

	// exercise 4.7

	size_t x;

	cout << "len of square Matrix ? ";
	cin >> x;

	// TODO : A malloc function to create a 2d array
	int** a = new int* [x]; 

	for (size_t i = 0; i < x; i++) {
		a[i] = new int[x];
	}

	randomArrayFill(a, x);
	showArray(a, x);
	localMax(a,x);

	// deleting memory

	for (size_t i = 0; i < x; i++)
		delete[] a[i];

	delete[] a;



	return 0;
}
