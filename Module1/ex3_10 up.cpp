#define _USE_MATH_DEFINES
#include <iostream>
#include <climits>
#include <cmath>
#include <assert.h>

using namespace std;

unsigned long long factorial_ite(unsigned int n);
unsigned long long factotial_rec(unsigned int n);
int gcd_rec(int m, int n);

double distance(double x1, double y1, double x2, double y2);

double area(double radius);
double area(double x1, double y1, double x2, double y2, double x3, double y3);
double area(double x1, double y1, double x2, double y2);

double integrateTR(double f(double), double a, double b, int n);
double g(double x);
double f(double x);

// TO REMEMBER LATER

/*
	enum Weekday { MONDAY, TUESDAY, WEDNESDAY, THURSDAY,
FRIDAY, SATURDAY, SUNDAY };
	Weekday homework_due_day = WEDNESDAY;
*/

int main() {

	// exercise 3.10

	/*
	for (int i = 1; i <= INT_MAX; i++) {
		unsigned long long a = factorial_ite(i);
		if (a * (i + 1) == 0) {
			cout << i << " -> " << a << " " << ULLONG_MAX << endl;
			cout << a * (i + 1);
			break;
		}
	} 
	*/

	// exercise 3.14

	/*
	cout << integrateTR(g, 0, 10, 1000) << endl;
	cout << integrateTR(f, -2, 2, 1000);
	*/



	return 0;
}

// 3.10

unsigned long long factorial_ite(unsigned int n) {
	unsigned long long fac{ 1 };
	for (int i = 2; i <= n; i++) {
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
double f(double x) { return sqrt( 4 - x*x); };