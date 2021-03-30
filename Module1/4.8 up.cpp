#include <vector>
#include <iostream>
#include <iomanip>
#include "Years_Month_days.h"
#include <string>
#include "4.7 and 4.8.h"

using namespace std;

int as(const void* x, const void* y) {
	return  (*(int*)x - *(int*)y);
}
void randFillArrPointer(int* a, size_t x) {
	srand(time(NULL));
	for (size_t i = 0; i < x; i++) {
		for (size_t j = 0; j < x; j++) {
			a[i*x + j + 1] = rand() % 10;
		}
	}
}
void showArrayPointer(int* a, size_t x) {
	cout << endl;
	for (size_t i = 0; i < x; i++) {
		for (size_t j = 0; j < x; j++) {
			cout << setw(2) << a[i * x + j + 1];
		}
		cout << endl;
	}
	cout << endl;
}

// exercise 4.12

void readArray(int* a, size_t nElem);
int findValueInArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2 = -1);
size_t findMultValuesInArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2, size_t* index);

int findValueInArray(const int* pos1, const int* pos2, int value);
size_t findMultValuesInArray(const int* pos1, const int* pos2, int value, size_t* index);

int main() {

	// exercise 4.8

	/*
	int year;
	const int Months_a_Year = 12;

	cout << "What year, madam ? " << endl; cin >> year;

	vector<vector<double>> pluviosity_year(12);

	randomPluviosityYear(pluviosity_year, year);

	cout << "Daily average Pluviosity = " << averagePluviosityDaily(pluviosity_year, year) << endl;
	cout << "Average Month Pluviosity : " << endl;
	for (int m = 0; m < Months_a_Year; m++) {
		cout << "   " << mapMonth(m + 1) << " = " << averagePluviosityMonth(pluviosity_year,year,m) << endl;
	}

	cout << "Maximum pluviosity at day(s): ";
	vector<string> v = maximumPluviosity(pluviosity_year, year);
	for (int x{}; x < v.size(); x++) {
		cout << "   " << v[x] << endl;
	}

	cout << "Above average pluviosity at day(s): ";
	vector<string> v2 = aboveAverage(pluviosity_year, year, averagePluviosityDaily(pluviosity_year, year));
	int sum{};
	for (int x{}; x < v2.size(); x++) {
		cout << "   " << v2[x] << endl;
		sum++;
	}
	cout << sum << " days.";
	*/

	//exercise 4.11

	/*
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
	
	// TODO : Sort based on colums too - DONE

	//for (size_t i = 0; i < x; i++) {
	//	qsort(a[i], x, sizeof(int), as);
	//}
	//showArray(a, x);

	// c)

	for (size_t i = 0; i < x; i++) {
		qsort(a[i], x/2, sizeof(int), as);
	}
	for (size_t i = 0; i < x; i++) {
		qsort(a[i] + x/2 , x - (x / 2), sizeof(int), as);
	}
	showArray(a, x);

	//int* v = (int*)malloc(sizeof(int) * x);
	//randFillArrPointer(v, x);
	//showArrayPointer(v, x);
	//qsort(v, x*x, sizeof(int), as);
	//showArrayPointer(v, x);
	*/

	// exercise 4.12

	size_t x;
	cout << "Lenght of array ... " << endl; cin >> x;

	int* a = (int*) malloc(sizeof(int) * x);
	readArray(a, x);
	cout << findValueInArray(a, x, 1, 0, 3) << endl;
	cout << findValueInArray(a, a + x, 1) << endl;

	size_t* r = (size_t*) malloc(sizeof(size_t) * x);
	size_t elements = findMultValuesInArray(a, x, 1, 0, 5, r);
	for (size_t i = 0; i < elements; i++)
		cout << r[i] << " , ";

	cout << endl;

	size_t* d = (size_t*)malloc(sizeof(size_t) * x);
	size_t element = findMultValuesInArray(a,a+x,1,d);
	for (size_t i = 0; i < element; i++)
		cout << d[i] << " , ";

	return 0;
}


// exercise 4.12

void readArray(int* a, size_t nElem) {
	for (size_t i = 0; i < nElem; i++) {
		cout << i << " ?"; cin >> a[i];
	}
}
int findValueInArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2) {
	if (pos2 == -1)
		pos2 = nElem - 1;
	// changed ...
	for (size_t i = pos1; i <= pos2; i++) {
		if (a[i] == value) {
			return i;
		}
	}
}
size_t findMultValuesInArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2, size_t* index) {
	size_t sum{};
	// putting another variable to help with the index of the array index[] would be better
	for (size_t x = 0; x < nElem; x++) {
		for (size_t i = pos1; i <= pos2; i++) {
			if (a[i] == value) {
				index[x] = i;
				sum++;
				pos1 = i + 1;
				break;
			}
		}
	}
	return sum;
}

int findValueInArray(const int* pos1, const int* pos2, int value) {
	// return the index based on the interval given
	int nElem = (pos2 - pos1);
	// changed ...
	for (int i = 0; i <= nElem; i = i ++) {
		if (*(pos1 + i) == value) {
			return i;
		}
	}
}
size_t findMultValuesInArray(const int* pos1, const int* pos2, int value, size_t* index) {
	size_t sum{};
	size_t nElem = (pos2 - pos1);
	size_t x1{};
	// putting another variable to help with the index of the array index[] would be better
	for (size_t x = 0; x < nElem; x++) {
		for (size_t i = x1; i <= nElem; i++) {
			if (*(pos1 + i) == value) {
				index[x] = i;
				sum++;
				x1 = i + 1;
				break;
			}
		}
	}
	return sum;
}
