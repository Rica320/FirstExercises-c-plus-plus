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
	
	// TODO : Sort based on colums too 

	/*for (size_t i = 0; i < x; i++) {
		qsort(a[i], x, sizeof(int), as);
	}
	showArray(a, x);*/

	// c)

	for (size_t i = 0; i < x; i++) {
		qsort(a[i], x/2, sizeof(int), as);
	}
	for (size_t i = 0; i < x; i++) {
		qsort(a[i] + x/2 , x - (x / 2), sizeof(int), as);
	}

	showArray(a, x);


	return 0;
}

// exercise 4.11