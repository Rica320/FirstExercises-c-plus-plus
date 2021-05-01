#include <vector>
#include <iostream>
#include <iomanip>
#include "Years_Month_days.h"
#include <string>
#include "4.7 and 4.8.h"
#include <sstream> 

using namespace std;

struct Fraction { 
	int numerator;
	int denominator;
};

struct Date { 
	unsigned int year, month, day; 
};

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

char encryptChar(char c, int key);
string encryptString(string  s, int  key);

string toupperString(string s1);
void bubbleSort(vector<string>& v, char order);

int com(const void* x, const void* y) {
	return  (*(int*)x - *(int*)y);
}

bool sequenceSearch(const string& s, int nc, char c);

string normalizeName(const string& name);

Fraction readFraction();
void performop(Fraction op1, Fraction op2, Fraction& result, char op);
void reduceFraction(Fraction& frac);
int gcd(int a, int b);

void readDate(Date* d);
void writeDate(const  Date* d);
int compareDates(const Date* d1, const Date* d2);
void  sortDates(Date* d1, Date* d2);

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

	/*
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
	*/

	// exercise 5.1

	/*
	string str;

	cout << "a string: ";
	getline(cin, str);

	cout << encryptString(str, 10) << endl;
	cout << encryptString(str, -10) << endl;

	return 0;*/

	// exercise 5.2

	/*
	vector<string> vec{"abc", "ABCD", "aec", "rpdm", "erfd"};

	bubbleSort(vec, 'a');
	for (int x = 0; x < vec.size(); x++) {
		cout << vec[x];
	}
	bubbleSort(vec, 'd');
	for (int x = 0; x < vec.size(); x++) {
		cout << vec[x];
	}*/

	// exercise 5.3

	/*
	// MAGICCCC // NOT WORKING
	char a[5][3] = { {'a','b','7'}, {'R','b','2'}, {'R','G','3'}, {'A','b','4'}, {'a','B','5'} };

	for (size_t i = 0; i < 5; i++) {
		for (size_t n = 0; n < 3; n++) {
			cout << a[i][n];
		}
		cout << endl;
	}

	cout << "After :" << endl;
	qsort(a, 5, sizeof(char)*3, com);
	for (size_t i = 0; i < 5; i++) {
		for (size_t n = 0; n < 3; n++) {
			cout << a[i][n];
		}
		cout << endl;
	}
	*/

	// exercise 5.4

	/*
	cout << sequenceSearch("abcddeedddf", 3, 'd');
	cout << sequenceSearch("abcddeedddf", 4, 'd');
	cout << sequenceSearch("abcddeeddddf", 4, 'd');
	cout << sequenceSearch("OLAOLAAA", 3, 'A');
	*/

	// exercise 5.5

	/*
	cout << normalizeName("   Maria da Felicidade dos Reis e Passos Dias de Aguiar   ") << endl;
	cout << normalizeName("   Ricardo André Araújo de Matos   ");
	*/

	// exercise 5.6

	/*
	// NOT As good as the 3.8 - nested operations and others operations to be done
	char operato;
	Fraction result{ 0,1 };

	do
	{
		Fraction op1 = readFraction();
		cin >> operato;
		Fraction op2 = readFraction();
		performop(op1, op2, result, operato);

	} while (0);

	cout << "result = " << result.numerator << "/" << result.denominator;
	*/

	// exercise 5.7

	Date Dat, d2{ 2020,5,6 };

	readDate(&Dat);
	writeDate(&Dat);
	cout << compareDates(&Dat, &d2) << endl;
	sortDates(&Dat, &d2);
	writeDate(&Dat);
	writeDate(&d2);

	return EXIT_SUCCESS;
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

// exercise 5.1

char encryptChar(char c, int key) {
	if ((int)'A' <= (int)(c) && (int)(c) <= (int)'Z') {
		c = char(int(c + key - 'A' + 26) % 26 + 'A');
	}
	if ((int)'a' <= (int)(c) && (int)(c) <= (int)'z') {
		c = char(int(c + key - 'a' + 26) % 26 + 'a');
	}
	return c;
}

string encryptString(string  s, int  key) {
	for (size_t i = 0; i < s.size(); i++) {
		s[i] = encryptChar(s[i], key);
	}
	return s;
}

// exercise 5.2

string toupperString(string s1) {
	for (int i = 0; i < s1.size(); i++) {
		s1[i] = toupper(s1[i]);
	}
	return s1;
}

void bubbleSort(vector<string>& v, char order) {

	for (size_t i = 0; i < v.size(); i++) {
		bool swap = false;
		for (size_t n = 0; n < v.size() - i - 1; n++) {
			if ((toupperString(v[n]) > toupperString(v[n + 1]) && order == 'a') || (toupperString(v[n]) < toupperString(v[n + 1]) && order == 'd')) {
				string temp = v[n];
				swap = true;
				v[n] = v[n + 1];
				v[n + 1] = temp;
			}
		}
		if (!swap)
			break;
	}
}

// exercise 5.4

bool sequenceSearch(const string& s, int nc, char c) {
	string tem(nc, c);
	if (s.find(tem) != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

// exercise 5.5

string normalizeName(const string& name) {
	string temp;
	size_t i1 = name.find_first_not_of(" ");
	size_t i2 = name.find_last_not_of(" ");
	vector<string> vec = { " DE ", " DO ", " DA ", " DOS ", " DAS ", " E "};

	temp = name.substr(i1, i2 - i1 + 1);
	
	for (int x = 0; x < temp.size(); x++)
		temp[x] = toupper(temp[x]);

	for (int x = 0; x < vec.size(); x++) {
		size_t i = temp.find(vec[x]);
		if (i != string::npos) {
			temp.erase(i+1, vec[x].size() - 2);
		}
	}
	return temp;
}

// exercise 5.6

Fraction readFraction() {
	Fraction x{ 0,1 };
	cin >> x.numerator;
	cin.ignore(1);
	cin >> x.denominator;

	return x;
}
void performop(Fraction op1, Fraction op2,Fraction& result, char op) {
	switch (op)
	{
	case '+':
		result.denominator = op1.denominator * op2.denominator;
		result.numerator = op1.numerator * op2.denominator + op2.numerator * op1.denominator;
		reduceFraction(result);
		break;
	case '-':
		result.denominator = op1.denominator * op2.denominator;
		result.numerator = op1.numerator * op2.denominator - op2.numerator * op1.denominator;
		reduceFraction(result);
		break;
	default:
		break;
	}
}
void reduceFraction(Fraction& frac) {
	int a = gcd(frac.numerator, frac.denominator);
	frac.numerator = frac.numerator / a;
	frac.denominator = frac.denominator / a;
}
int gcd(int a, int b) {
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a == 0 || b == 0)
		if (a == 0)
			return b;
		else
			return a;
	while (a != b)
	{
		if (a < b)
			b -= a;
		else
			a -= b;
	}
	return a;
}

// exercise 5.7

void readDate(Date* d) {
	cin >> d->year;
	cin.ignore(10000, '/');
	cin >> d->month;
	cin.ignore(10000, '/'); 
	cin >> d->day;
	return;
}

void  writeDate(const  Date* d) {
	ostringstream oss;
	oss << setw(4) << d->year << setfill('0')
		<< '/' << setw(2) << d->month << setfill('0')
		<< '/' << setw(2) << d->day << setfill('0');
	cout << oss.str() << "\n";
}

int compareDates(const Date* d1, const Date* d2) {
	int y, m, d;

	y = d1->year - d2->year;
	m = d1->month - d2->month;
	d = d1->day - d2->day;

	return (y * 999999 + m * 999 + d >= 0) ? ((y * 999999 + m * 999 + d == 0) ? 0 : 1) : -1;
}
void  sortDates(Date* d1, Date* d2) {
	if (compareDates(d1, d2) > 0) {
		Date temp = *d2;
		*d2 = *d1;
		*d1 = temp;
	}
}