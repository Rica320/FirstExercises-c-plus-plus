#include <vector>
#include <iostream>
#include <iomanip>
#include "Years_Month_days.h"
#include <string>

using namespace std;

void randomPluviosityYear(vector<vector<double>>& vec, int year);
double averagePluviosityDaily(const vector<vector<double>>& vec, int year);
double averagePluviosityMonth(const vector<vector<double>>& vec, int year, int month);
vector<string> maximumPluviosity(const vector<vector<double>>& vec, int year);
vector<string> aboveAverage(const vector<vector<double>>& vec, int year, double ave);

int main() {

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

	return 0;
}

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