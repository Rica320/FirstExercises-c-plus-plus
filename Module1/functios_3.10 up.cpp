#define _USE_MATH_DEFINES
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;


// 3.10

unsigned long long factorial_ite(unsigned int n) {
	unsigned long long fac{ 1 };
	for (unsigned int i = 2; i <= n; i++) {
		fac *= i;
	}return fac;
}

unsigned long long factotial_rec(unsigned int n) {
	if (n == 1 || n == 0)
		return 1;
	return n * factotial_rec(n - 1);
}

// 3.11

int gcd_rec(int m, int n) {
	if ((m % n) == 0)
		return n;
	return gcd_rec(n, m % n);
}

// 3.12

double distance(double x1, double y1, double x2, double y2) {
	return pow(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0), 0.5);
}

double area(double radius) {
	return M_PI * pow(radius, 2);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double s, a, b, c;
	a = distance(x1, y1, x2, y2);
	b = distance(x1, y1, x3, y3);
	c = distance(x2, y2, x3, y3);
	s = (a + b + c) / 2;
	return pow(s * (s - a) * (s - b) * (s - c), 0.5);
}

double area(double x1, double y1, double x2, double y2) {
	double c, l;
	c = distance(x1, y1, x2, y1);
	l = distance(x1, y1, x1, y2);
	return l * c;
}

// 3.14

double integrateTR(double f(double), double a, double b, int n) {
	double h = (b - a) / n, sum{};
	for (int i = 1; i <= n; i++) {
		sum += (h / 2) * (f(a + (i - 1) * h) + f(a + i * h));
	}
	return sum;
}
double g(double x) { return x * x; };
double f(double x) { return sqrt(4 - x * x); };

// exercise 4.1 

void  readArray(int  a[], size_t nElem) {
	for (size_t i = 0; i < nElem; i++) {
		cout << i << " ?"; cin >> a[i];
	}
}

int findValueInArray(const  int  a[], size_t nElem, int value, size_t pos1, size_t pos2) {
	if (pos2 == -1)
		pos2 = nElem - 1;
	// changed ...
	for (size_t i = pos1; i <= pos2; i++) {
		if (a[i] == value) {
			return i;
		}
	}
}

size_t findMultValuesInArray(const  int  a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]) {
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

// exercise 4.2

vector<int> readVector() {
	vector<int> vec;
	// Can improve by turning the do loop to a while()
	do {
		static int i = 0;
		int x;
		cout << i << " ?"; cin >> x;
		if (cin.fail() && cin.eof())
			break;
		vec.push_back(x);
		i++;
	} while (!cin.fail() && !cin.eof());
	return vec;
}

size_t findValueInVector(const vector<int>& v, int value, size_t pos1, size_t pos2) {
	for (size_t i = pos1; i <= pos2; i++) {
		if (v[i] == value) {
			return i;
		}
	}
	return 9999; // representing a Miss
}

vector<size_t> findMultValuesInVector(const vector<int>& v, int value, size_t pos1, size_t pos2) {
	vector<size_t> vec;
	for (size_t i = pos1; i <= pos2; i++) {
		if (v[i] == value) {
			vec.push_back(i);
		}
	}
	return vec;
}

// exercise 4.3

vector<int> randomVector() {
	vector<int> vec;
	srand(time(NULL));
	int sizeVector = rand() % 240;
	for (int i = 0; i < sizeVector; i++) {
		vec.push_back(rand() % 1000 - 200);
	}
	return vec;
}

void bubblesort(vector<int>& avector, char d) {
	// line c) ... improving function by the way require
	for (size_t i = 0; i < avector.size(); i++) {
		bool swap = false;
		for (size_t n = 0; n < avector.size() - i - 1; n++) {
			if ((avector[n] > avector[n + 1] && d == 'a') || (avector[n] < avector[n + 1] && d == 'd')) {
				int temp = avector[n];
				swap = true;
				avector[n] = avector[n + 1];
				avector[n + 1] = temp;
			}
		}
		if (!swap)
			break;
	}
}
void bubblesort(vector<int>& avector, bool f(int x, int y)) {
	for (size_t i = 0; i < avector.size(); i++) {
		bool swap = false;
		for (size_t n = 0; n < avector.size() - i - 1; n++) {
			if (f(avector[n + 1], avector[n])) {
				int temp = avector[n];
				swap = true;
				avector[n] = avector[n + 1];
				avector[n + 1] = temp;
			}
		}
		if (!swap)
			break;
	}
}

void showVector(const vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		if (i == vec.size() - 1) {
			cout << vec[i] << endl;
			break;
		}
		cout << vec[i] << ',';
	}
}

// exercise 4.4

int binarySearch(const  vector<int>& v, int  value) {
	//returns the index of the value wanted in a sorted vector
	bool found = false;
	size_t first = 0, last = v.size(), middle;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (v[middle] == value) {
			found = true;
		}
		else if (v[middle] > value) {
			last = middle - 1;
		}
		else if (v[middle] < value) {
			first = middle + 1;
		}
	}
	if (found)
		return middle;
	else
		return -1; // Not in the vector

}

// exercise 4.5

void  removeDuplicates(vector<int>& v) {
	// Removing duplicates without an auxiliar vector
	// Order should be the same
	size_t size = v.size();
	for (size_t i = 0; i < size; i++) {
		for (size_t n = 0; n < i; n++) {
			if (v[n] == v[i]) {
				// duplicate is found
				for (size_t x = i; x < size - 1; x++) {
					v[x] = v[x + 1];
				}
				v.resize(size - 1);
				size--;
				n--;
				i--;
			}
		}
	}
}

// exercise 4.6

void vectorUnion(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) {
	// being v3 a empty vector 
	auto ascending = [](int x, int y) {return x < y; };
	for (size_t i = 0; i < v1.size(); i++) {
		v3.push_back(v1[i]);
	}
	for (size_t i = 0; i < v2.size(); i++) {
		v3.push_back(v2[i]);
	}
	removeDuplicates(v3);
	bubblesort(v3, ascending);
}
void vectorIntersection(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) {
	// being v3 a empty vector 
	for (size_t i = 0; i < v1.size(); i++) {
		for (size_t n = 0; n < v2.size(); n++) {
			if (v1[i] == v2[n]) {
				v3.push_back(v1[i]);
				break;
			}
		}
	}
	removeDuplicates(v3);
}