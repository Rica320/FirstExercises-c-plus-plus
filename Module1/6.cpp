/*
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main() {
	int x1, x2, x3;
	int y1, y2, y3;
	double s, a, b, c;
	cout << "Vertice 1('x y')";
	scanf_s("%d %d", &x1, &y1);
	cout << "Vertice 2('x y')";
	scanf_s("%d %d", &x2, &y2);
	cout << "Vertice 3('x y')";
	scanf_s("%d %d", &x3, &y3);

	a = pow(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0), 0.5);
	b = pow(pow(x3 - x1, 2.0) + pow(y3 - y1, 2.0), 0.5);
	c = pow(pow(x2 - x3, 2.0) + pow(y2 - y3, 2.0), 0.5);
	s = (a + b + c) / 2;

	cout << "Area = " << pow(s*(s-a)*(s-b)*(s-c), 0.5);

	return 0;

}
*/