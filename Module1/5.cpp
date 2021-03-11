/*
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int h1, m1, s1, h2, m2, s2;
	int d, h, m, s;

	cout << "Time1 (hours minutes seconds) ?";
	scanf_s("%d %d %d", &h1, &m1, &s1);
	cout << "Time2 (hours minutes seconds) ?";
	scanf_s("%d %d %d", &h2, &m2, &s2);

	s = (s1 + s2) % 60;
	m = (m1 + m2 + (s1 + s2) / 60) % 60;
	h = (h1 + h2 + (m1 + m2 + (s1 + s2) / 60) / 60) % 24;
	d = (h1 + h2 + (m1 + m2 + (s1 + s2) / 60) / 60) /24;

	cout << "Time1 + Time2  = " << d << " day, " << h << " hours, " << m << " minutes and " << s << " seconds";


	return 0;
}
 */