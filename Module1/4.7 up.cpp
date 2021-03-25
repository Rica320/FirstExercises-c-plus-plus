#include <iostream>
#include <cstdlib>
#include <iomanip>	

using namespace std;

void localMax(int** a, size_t size); 
void randomArrayFill(int**& a, size_t x);
void showArray(int** a, size_t x);
bool clearNeighborhood(int**& a, size_t i, size_t j);


int main() {

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

// exercise 4.7

bool clearNeighborhood(int**& a, size_t i, size_t j) {
	int temp = a[i][j];
	if (a[i - 1][j - 1] < temp && a[i][j - 1] < temp && a[i - 1][j + 1] < temp && a[i - 1][j] < temp && a[i + 1][j] < temp && a[i][j + 1] < temp && a[i + 1][j + 1] < temp && a[i + 1][j - 1] < temp)
		return true;
	else
		return false;
}
void localMax(int** a, size_t size) {
	// checks for the max values of an array
	// border integer should not be consider
	for (size_t i = 1; i < size - 1; i++) {
		for (size_t j = 1; j < size - 1; j++) {
			if (clearNeighborhood(a,i,j)) {
				cout << "a[" << i << "][" << j << "] =" << a[i][j] << "is a max" << endl;
			}
		}
	}
}
void randomArrayFill(int**& a, size_t x) {
	// only for square arrays
	srand(time(NULL));
	for (size_t i = 0; i < x; i++) {
		for (size_t j = 0; j < x; j++) {
			a[i][j] = rand() % 10;
		}
	}
}
void showArray(int** a, size_t x) {
	cout << endl;
	for (size_t i = 0; i < x; i++) {
		for (size_t j = 0; j < x; j++) {
			cout << setw(2) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}