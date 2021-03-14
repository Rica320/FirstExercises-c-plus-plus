#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <ios>
#include <limits>
#include <iomanip>
#include <chrono>
#include <new>
#include <string>
using namespace std;

// exercise 3.1.

/*
double distance(double x1, double y1, double x2, double y2) {
	return pow(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0), 0.5);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double s, a, b, c;
	a = distance(x1, y1, x2, y2);
	b = distance(x1, y1, x3, y3);
	c = distance(x2, y2, x3, y3);
	s = (a + b + c) / 2;
	return pow(s * (s - a) * (s - b) * (s - c), 0.5);
}
*/

// exercise 3.2

/*
bool isprime(int& n) {
	bool prime = true;
	if (n == 1 || n == 0)
		return false;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}
*/

// exercise 3.3

/*
double root(double& n, double& delta, int& nMaxIter) {
	double rq = 1, rqn{ 1 };
	int PRECISION{};
	double i = delta - (int)delta;

	while (i != 0) {
		PRECISION += 1;
		i = i * 10;
		i = i - (int)i;
	}
	cout << fixed << setprecision(PRECISION) << endl;

	while (nMaxIter != 0 && abs(n - pow(rqn, 2)) > delta) {
		rqn = (rq + n / rq) / 2;
		rq = rqn;
		nMaxIter--;
	}
	return rq;
}
*/

//exercise 3.4

/*
double round(double& x, unsigned& n) {
	return floor(x * pow(10, n) + 0.5) / pow(10, n);
}
*/

// exercise 3.5

/*
int gcd(int& a, int& b) {
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
*/

// exercise 3.6.

/*
int time_counter() {
	static chrono::steady_clock sc;
	static auto last_time = sc.now();
	auto start = sc.now();
	auto time = static_cast<chrono::duration<double>>(start - last_time);
	last_time = start;
	return time.count();
}
*/

// exercise 3.7. -- TODO

/*
bool readInt(int& x) {
	char str[256];
	cin >> x;
	if (cin.fail()) {
		return false;
	}
	if () {
		cin.ignore(1000000, '\n');
		return false;
	}
	cin.ignore(1000000, '\n');
	return true;
}
*/

int main() {

	/*
	int max = - INFINITY;
	int min = 999999;
	for (int i = 0; i < 3; i++) {
		int temp;
		cin >> temp;
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	}
	cout << "MAX =" << max << endl;
	cout << "MIN =" << min << endl;
	*/

	/*
	vector<int> vec;
	for (int i = 0; i < 3; i++) {
		int temp;
		cout << "Introduce no. " << i + 1 ;
		cin >> temp;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000000, '\n');
			i--;
		}
		else {
			vec.push_back(temp);
		}
	}
	cout << "Here they are:";
	for (int i = 2; i >= 0; i--) {
		cout << vec[i] << " ";
	}
	*/
	/*
	vector<int> vec;
	int max = 0;
	for (int i = 0; i < 3; i++) {
		int temp;
		cin >> temp;
		if (temp < 0) {
			cout << "A positive please";
			i--;
		}
		else {
			if (temp > max) {
				if (max != 0)
					vec.push_back(max);
				max = temp;
			}
			else {
				vec.push_back(temp);
			}
		}
	}
	int sum{};
	for (int i = 0; i < 2; i++) {
		sum += vec[i];
	}
	if (sum >= max)
		cout << "IS IT? YES";
	else
		cout << "IS IT? NO";


	*/

	// exercise 2.3

	/*
	double a, b;
	cin >> a >> b;
	if (a + b > INT_MAX)
		cout << "sum overflow!!";
	else if (a + b < INT_MIN)
		cout << "sum underflow!!";
	else
		cout << "You are save, Folk!!";
	*/

	// exercise 2.4

	/*
	double weight , cost;
	cout << "What's the mass of your merchandise (grams)?";
	cin >> weight;

	if (weight <= 500)
		cost = 5;
	else if (500 < weight <= 1000) {
		cost = 5 + 1.5 * ((weight - 500) / 100);
	}
	else {
		cost = 12.5 + 5 * ((weight - 1000) / 250);
	}

	cout << cost;
	*/

	// exercise 2.5

	/*
	double a, b, c, root1, root2;

	cout << "Solution of Ax^2 + Bx + C= 0" << endl;
	cout << "Insert the coefficients(ABC): ";
	cout << fixed << setprecision(3);
	cin >> a >> b >> c;

	if (pow(b, 2.0) - 4 * a * c < 0) {
		cout << "The equation has 2 complex roots: " << -b / (2 * a) << " + " << pow(-(pow(b, 2.0) - 4 * a * c), 0.5) / (2 * a) <<
		"i and " << -b / (2 * a) << " - " << pow(-(pow(b, 2.0) - 4 * a * c), 0.5) / (2 * a) <<"i\n";
	}
	else if (pow(b, 2.0) - 4 * a * c == 0) {
		root1 = (-b + pow(pow(b, 2.0) - 4 * a * c, 0.5)) / 2 * a;
		cout << "The equation has 2 equal roots: " << root1;
	}
	else {
		root1 = (-b + pow(pow(b, 2.0) - 4 * a * c, 0.5)) / (2 * a);
		root2 = (-b - pow(pow(b, 2.0) - 4 * a * c, 0.5)) / (2 * a);

		cout << "The equation has 2 different roots: " << root1 << " and " << root2;
	}
	*/

	// exercise 2.6

	/*
	double q{}, j, a;
	int n;
	int temp;

	cout << "Amount in the bank : " << endl;
	cin >> a;
	cout << "Interest rate (%) : " << endl;
	cin >> j;
	cout << "years : " << endl;
	cin >> n;

	temp = n;

	for (n; n != 0; n--) {
		q = q * (j / 100) + q + a;
	}

	cout << "After " << temp << " years you have " << q << endl;
	*/

	// exercise 2.7 a)

	/*
	int test , range;
	bool prime = true;

	cout << "Tell us a number!!!";
	cin >> test;

	range = (int) sqrt(test);


	for (int i = 2; range >= i; i++) {
		if ((0 == (test % i) && i != test) || test == 1) {
			cout << "NOT PRIME!!";
			prime = false;
			break;
		}
		else if (test == i) {
			break;
		}
	}
	if (prime) {
	cout << "A PRIMEEEEE";
	}
	*/

	// exercise 2.7 b)
	
	/*
	for (int n = 1; n < 1000; n++) {
		int range;
		bool prime = true;
		range = (int)sqrt(n);
		for (int i = 2; range >= i; i++) {
			if (((n % i) == 0 && i != n) || n == 1) {
				prime = false;
				break;
			}
			else if (n == i) {
				break;
			}
		}
		if (prime) {
			cout << n << endl;

		}
	}
	*/

	// exercise 2.7 c)

	/*
	int sum{};
	for (int n = 1; sum <= 100; n++) {
		int range;
		bool prime = true;
		range = (int)sqrt(n);
		for (int i = 2; range >= i; i++) {
			if (((n % i) == 0 && i != n) || n == 1) {
				prime = false;
				break;
			}
			else if (n == i) {
				break;
			}
		}
		if (prime) {
			cout << n << endl;
			sum += 1;
		}
	}
	*/

	// exercise 2.7 c)
	
	/*
	unsigned long n = ULONG_MAX;
	bool found = false;
	
	while (!found) {
		int range;
		found = true;
		range = (int)sqrt(n);
		for (int i = 2; range >= i; i++) {
			if (((n % i) == 0 && i != n) || n == 1) {
				found = false;
				break;
			}
			else if (n == i) {
				break;
			}
		}
		n--;
	}
	cout << n + 1;
	*/

	// exercise 2.8
	
	/*
	float a, b, steps;
	cout << tan(M_PI / 2);
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "range[0] range[1] steps?";
		cin >> a >> b >> steps;
	} while (cin.fail());
	cout << fixed << setprecision(6);
	cout << setw(5) << "ang" << setw(10) << "sin" << setw(10) << "cos" << setw(10) << "tan" << setw(5) << endl;
	while (a <= b) {
		int i = (a / 1);
		if (i % 90 != 0 || i == 0)
			cout << setw(3) << a << setw(10) << sin(a* M_PI / 180) << setw(10) << cos(a * M_PI / 180) << setw(10) << tan(a * M_PI / 180) << setw(5) << endl;
		else 
			cout << setw(3) << a << setw(10) << sin(a * M_PI / 180) << setw(10) << cos(a * M_PI / 180) << setw(10) << "  infinitive" << setw(5) << endl;
		a += steps;
	}
	*/
	
	// exercise 2.9

	/*
	unsigned int i, copy{}, temp, len = 1, a;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Let's test your palindrome skills!!! cin a int ...";
		cin >> i;
	} while (cin.fail());

	temp = i;

	while (temp / 10 != 0) {
		len++;
		temp = temp / 10;
	}

	temp = i;
	a = len;

	while (temp != 0) {
		copy = copy + temp % 10 * pow(10, len - 1);
		temp /= 10;
		len--;
	}
	if (copy == i)
		cout << "MA FRIEND, THAT's GOLD!!!" << endl;
	else
		cout << "HOuston WE HaVE A BiG PRoblEM" << endl;
	*/

	// exercise 2.10
	
	/*
	unsigned int number;

	cout << "tell a int to break it down into prime factors";
	cin >> number;

	// check if the number is an int in a code above ( not the optimal algorithm) adaptation of exercise 2.7(wich is wrong)  b code
	// consider that the number is not a prime

	vector<int> vec;
	for (int n = 1; n < 10000; n++) {
		int range;
		bool prime = true;
		range = (int)sqrt(n);
		for (int i = 2; range >= i; i++) {
			if (((n % i) == 0 && i != n) ) {
				prime = false;
				break;
			}
			else if (n == i) {
				break;
			}
		}
		if (prime && n!=1) {
			vec.push_back(n);
		}
	}

	cout << number << " = ";

	int temp{};

	while (number != 1) {
		while (number % vec[temp] == 0) {
			number /= vec[temp];
			cout << vec[temp] << "x";
		}
		temp++;
	}

	cout <<"1"<< endl;
	*/

	// exercise 2.11 a)

	/*
	int n, d=1;
	double sum{};

	cout << "Sum of the first n elements ...(tell us the n)";
	cin >> n;

	for (int i = 1; i != n + 1; i++, d = d + 2) {
		if (i % 2 == 1)
			sum += (4.0 / d);
		else
			sum -= (4.0 / d);
	}
	cout << sum;
	*/

	// exercise 2.11 b)

	/*
	double sum{};
	int a{}, n;

	cout << "Sum of the first n elements ...(tell us the n)";
	cin >> n;
	double last = 1;

	for (n; n != 0; n-- , a++) {
		if (a == 0) {
			sum += 1;
			last = 1;
		}
		else {
			sum += last / a;
			last = last / a;
		}
	}
	cout << sum;
	*/

	// exercise 2.11 c)

	/*
	int x, n, a{};
	double last = 1, sum{};
	cout << "Sum of the first n elements ...(tell us the n and a x)";
	cin >> n >> x;

	for (n; n != 0; n--, a++) {
		if (a == 0) {
			sum += 1;
			last = 1;
		}
		else {
			if (a % 2 == 1)
				sum -= last * x / a;
			else 
				sum += last * x / a;
			last = last * x / a;
		}
	}
	cout << sum;
	*/

	// exercise 2.12

	/*
	int x, a{}, control{};
	double last = 1, sum{}, asum{}, p;

	cout << "Series, stop at precision p ...(tell us the p and a x)";
	cin >> p >> x;

	while (abs(asum - sum) > p || control < 3) {
		asum = sum;
		if (a == 0) {
			sum += 1;
			last = 1;
		}
		else {
			if (a % 2 == 1)
				sum -= last * x / a;
			else
				sum += last * x / a;
			last = last * x / a;
		}
		a++;
		control++;
	}
	cout << sum;
	*/

	// exercise 2.13 a)

	/*
	int n, small{ 9999 }, max{-9999},x;
	double mean{}, stddev{};
	vector<int> vec;

	cout << "what len do you  want...";
	cin >> n;


	for (int i = n; i != 0; i--) {
		cin >> x;
		if (x > max)
			max = x;
		else if (x < small)
			small = x;
		mean += x;
		vec.push_back(x);
	}
	cout << "sum = " << mean << endl;
	mean /= n;
	cout << "mean = " << mean << endl;
	cout << "smallest = " << small << endl;
	cout << "largest = " << max << endl;

	for (int i = n; i != 0; i--) {
		stddev += pow(vec[i-1] - mean, 2.0);
	}
	stddev = sqrt(stddev / n);
	cout << "standart deviation = " << stddev;
	*/

	// exercise 2.13 b)

	/*
	int n{}, small{ 9999 }, max{ -9999 }, x;
	double mean{}, stddev{};
	vector<int> vec;

	cout << "enter the numbers...";
	
	while (true) {
		cin >> x;
		if (x == 0)
			break;
		if (x > max)
			max = x;
		else if (x < small)
			small = x;
		mean += x;
		n += 1;
		vec.push_back(x);
	}
	cout << "sum = " << mean << endl;
	mean /= n;
	cout << "mean = " << mean << endl;
	cout << "smallest = " << small << endl;
	cout << "largest = " << max << endl;

	for (int i = n; i != 0; i--) {
		stddev += pow(vec[i - 1] - mean, 2.0);
	}
	stddev = sqrt(stddev / n);
	cout << "standart deviation = " << stddev;
	*/

	// exercise 2.13 c)

	/*
	int n{}, small{ 9999 }, max{ -9999 }, x;
	double mean{}, stddev{};
	vector<int> vec;

	cout << "enter the numbers...";

	while (true) {
		cin >> x;
		if (cin.fail() && cin.eof()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		if (x > max)
			max = x;
		else if (x < small)
			small = x;
		mean += x;
		n += 1;
		vec.push_back(x);
	}
	cout << "sum = " << mean << endl;
	mean /= n;
	cout << "mean = " << mean << endl;
	cout << "smallest = " << small << endl;
	cout << "largest = " << max << endl;

	for (int i = n; i != 0; i--) {
		stddev += pow(vec[i - 1] - mean, 2.0);
	}
	stddev = sqrt(stddev / n);
	cout << "standart deviation = " << stddev;
	*/
	
	// exercise 2.14 a and b

	/*
	double n, rq = 1, rqn{1}, delta;
	int nMaxIter, PRECISION{};

	cout << "tell us a number and we will predict is root... tell us too a delta and a nMaxIter";
	cin >> n >> delta >> nMaxIter;
	double i = delta - (int)delta;

	while (i != 0) {
		PRECISION += 1;
		i = i * 10;
		i = i - (int)i;
	}
	cout << fixed << setprecision(PRECISION) << endl;

	while (nMaxIter != 0 && abs(n - pow(rqn, 2)) > delta) {
		rqn = (rq + n / rq) / 2;
		rq = rqn;
		nMaxIter--;
	}
	cout << rq << endl;
	cout << sqrt(n) << endl;
	*/

	// exercise 2.15

	/*
	int a, b, c;

	chrono::steady_clock sc;
	srand(time(NULL));

	do {
	a = rand() % 7 + 2;
	b = rand() % 7 + 2;

	cout << a << " x " << b << " = " << endl;

	auto start = sc.now();

	cin >> c;

	auto end = sc.now();
	auto time_span = static_cast<chrono::duration<double>>(end - start);

	if (c != a * b)
		cout << "Very Bad" << endl;
	else if (time_span.count() < 5)
		cout << "Good!!!" << endl;
	else if (time_span.count() <= 10)
		cout << "Satisfactory!!!" << endl;
	else
		cout << "Insufficient" << endl;;
	cout << "Time : " << time_span.count() << endl;
	} while (!cin.fail());
	*/

	// exercise 2.16

	/*
	bool fail = false;
	double n, x, r;
	char chr;
	double* memory;
	int counter{};
	memory = new (nothrow) double[5];
	
	do {
		cin >> ws;
		n = cin.peek();
		if (isdigit(n)) {
			cin >> n;
			cin >> chr;
		}
		else if (isalpha(n)) {
			cin >> chr;
			n = r;
			cin.clear();
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			fail = true;
		}
		switch (chr)
		{
		case '+':
			cin >> x;
			system("cls");
			r = n + x;
			cout << r << endl;
			break;
		case '-':
			cin >> x;
			system("cls");
			r = n - x;
			cout << r << endl;
			break;
		case '*':
			cin >> x;
			system("cls");
			r = n * x;
			cout << r << endl;
			break;
		case '/':
			cin >> x;
			system("cls");
			r = n / x;
			cout << r << endl;
			break;
		case 'M':
			char chr2;
			cin >> chr2;
			switch (chr2)
			{
			case '+':
				cin >> x;
				system("cls");
				memory[counter % 5] += x;
				cout << memory[counter % 5] << endl;
				break;
			case '-':
				cin >> x;
				system("cls");
				memory[counter % 5] -= x;
				cout << memory[counter % 5] << endl;
				break;
			case 'R':
				system("cls");
				cout << "At Memory : \n";
				for (int c = 0; c < 5; c++)
					cout << memory[c] << ", ";
				break;
			case '.':
				system("cls");
				memory[counter % 5] = r;
				counter++;
				break;
			default:
				break;
			}
			break;
		case 'C':
			for (int c = 0; c < 5; c++)
				memory[c] = 0;
			cout << "At Memory now : \n";
			for (int c = 0; c < 5; c++)
				cout << memory[c] << ", ";
			break;
		default:
			break;
		}
	} while (!fail);
	*/

	// exercise 3.1.

	/*
	double x1, x2, x3;
	double y1, y2, y3;

	cout << "Vertice 1('x y')";
	cin >> x1 >> y1;
	cout << "Vertice 2('x y')";
	cin >> x2 >> y2;
	cout << "Vertice 3('x y')";
	cin >> x3 >> y3;

	cout << "Area = " << area(x1, y1, x2, y2, x3, y3);
	*/

	// exercise 3.2.

	/*
	int a;
	bool c;

	do {
		cout << "a number: \n";
		cin >> a;
		c = isprime(a);
		if (c)
			cout << a << " is a prime" << endl;
		else
			cout << a << " is not a prime" << endl;
	} while (!cin.fail());
	*/

	// exercise 3.3.

	/*
	double x, p;
	int max;

	do {
		cout << "Root of:" << endl;
		cin >> x;
		cout << "Precision of:" << endl;
		cin >> p;
		cout << "Max interations of:" << endl;
		cin >> max;
		cout << root(x, p, max) << endl;
	} while (!cin.fail());
	*/

	// exercise 3.4.
	
	/*
	double x;
	unsigned n;
	do {
		cout << "x : \n";
		cin >> x;
		cout << "decimal places : \n";
		cin >> n;
		cout << "round...ing :) ... \n" << round(x, n) << endl;

	} while (!cin.fail());
	*/

	// exercise 3.5.

	/*
	int a, b;

	cout << "tell us 2 numbers ... \n";
	cin >> a >> b;

	cout << "gcd = " << gcd(a, b);
	*/

	// exercise 3.6.
	
	/*
	do {
		cout << "Call?";
		cin.ignore();
		if (cin.get() == '\n') {
			cout << time_counter() << endl;
		}
	} while (!cin.fail());
	*/

	// exercise 3.7.
	
	/*
	int x;
	do {
		cout << "another?"<< endl;
		if (readInt(x));
			cout << x << endl;
	} while (!cin.fail());
	*/

	return 0;
}