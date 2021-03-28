#include <iostream>
#include <cstdlib>
#include <iomanip>	
#include <vector>
#include "Years_Month_days.h"

using namespace std;

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
			if (clearNeighborhood(a, i, j)) {
				cout << "a[" << i << "][" << j << "] = " << a[i][j] << "is a max" << endl;
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

// exercise 4.8

void randomPluviosityYear(vector<vector<double>>& vec, int year) {
	const int Months_a_Year = 12;
	srand(time(NULL));
	for (int m = 0; m < Months_a_Year; m++) {
		int dm = daysMonth(m + 1, year);
		for (int d = 0; d < dm; d++) {
			vec[m].push_back(rand() * 1.0 / RAND_MAX);
		}
	}
}
double averagePluviosityDaily(const vector<vector<double>>& vec, int year) {
	double sum = 0;
	const int Months_a_Year = 12;
	for (int m = 0; m < Months_a_Year; m++) {
		int dm = daysMonth(m + 1, year);
		for (int d = 0; d < dm; d++) {
			sum += vec[m][d];
		}
	}
	if (isLeapYear(year))
		return sum / 366;
	else
		return sum / 365;
}
double averagePluviosityMonth(const vector<vector<double>>& vec, int year, int month) {
	int dm = daysMonth(month + 1, year);
	double sum{};
	for (int d = 0; d < dm; d++) {
		sum += vec[month][d];
	}
	return static_cast<double>(sum / dm);
}
vector<string> maximumPluviosity(const vector<vector<double>>& vec, int year) {
	vector<string> re;
	int  Months_a_Year = 12;
	double max{};
	for (int m = 0; m < Months_a_Year; m++) {
		int dm = daysMonth(m + 1, year);
		for (int d = 0; d < dm; d++) {
			if (vec[m][d] > max) {
				max = vec[m][d];
			}
		}
	}
	for (int m = 0; m < Months_a_Year; m++) {
		int dm = daysMonth(m + 1, year);
		for (int d = 0; d < dm; d++) {
			if (vec[m][d] == max) {
				re.push_back(to_string(d + 1) + " of " + mapMonth(m + 1));
			}
		}
	}
	return re;
}
vector<string> aboveAverage(const vector<vector<double>>& vec, int year, double ave) {
	vector<string> re;
	int  Months_a_Year = 12;
	for (int m = 0; m < Months_a_Year; m++) {
		int dm = daysMonth(m + 1, year);
		for (int d = 0; d < dm; d++) {
			if (vec[m][d] > ave) {
				re.push_back(to_string(d + 1) + " of " + mapMonth(m + 1));
			}
		}
	}
	return re;
}
