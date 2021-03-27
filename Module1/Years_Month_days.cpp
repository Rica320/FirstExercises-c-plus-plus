#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int daysMonth(int month, int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 2 && isLeapYear(year))
		return 29;
	else if (month == 2) {
		return 28;
	}
	else
		return 30;
}

int dayWeek(int year, int month, int day) {
	// return the day of the week of a given day (0 meaning saturday I think)

	int c;
	// Can improve code
	switch (month)
	{
	case 1:
		if (isLeapYear(year))
			c = 6;
		else
			c = 0;
		break;
	case 2:
		if (isLeapYear(year))
			c = 2;
		else
			c = 3;
		break;
	case 3:
		c = 3;
		break;
	case 4:
		c = 6;
		break;
	case 5:
		c = 1;
		break;
	case 6:
		c = 4;
		break;
	case 7:
		c = 6;
		break;
	case 8:
		c = 2;
		break;
	case 9:
		c = 5;
		break;
	case 10:
		c = 0;
		break;
	case 11:
		c = 3;
		break;
	case 12:
		c = 5;
		break;
	default:
		break;
	}
	// will not work to years < 1000 ?? it Works
	return (5 * (year % 100) / 4 + c + day - 2 * ((year / 100) % 4) + 7) % 7;
}

string	mapMonth(int month) {
	vector<string> vec = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
		"October", "November", "December" };
	return vec[month - 1];
}

void printMonth(int month, int year) {
	// tansform month integer to names later - DONE
	cout << mapMonth(month) << '/' << year << endl;
	int first = dayWeek(year, month, 1);
	int dayaMonth = daysMonth(month, year);
	int k = (first - 1 + 7) % 7;
	cout << "Sun" << setw(6) << "Mon" << setw(6) << "Tue" << setw(6) << "Wed" << setw(6) << "Thu" << setw(6) << "Fri" << setw(6) << "Sat" << endl;
	cout << setw(k * 6 + 3);
	for (int i = 1; i <= dayaMonth; i++, k = (k + 1) % 7) {
		if (i != 1)
			if (k == 0)
				cout << setw(3) << i;
			else
				cout << setw(6) << i;
		else
			cout << i;
		if (k == 6)
			cout << endl;
	}
}