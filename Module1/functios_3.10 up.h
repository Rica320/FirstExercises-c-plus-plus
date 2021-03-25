#include <vector>
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

void  readArray(int a[], size_t nElem);
int findValueInArray(const  int  a[], size_t nElem, int value, size_t pos1 = 0, size_t pos2 = -1);
size_t findMultValuesInArray(const  int  a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]);

vector<int> readVector();
size_t findValueInVector(const vector<int>& v, int value, size_t pos1, size_t pos2);
vector<size_t> findMultValuesInVector(const vector<int>& v, int value, size_t pos1, size_t pos2);

vector<int> randomVector();
void bubblesort(vector<int>& avector, char d);
void bubblesort(vector<int>& avector, bool f(int x, int y));
void showVector(const vector<int>& vec);

int binarySearch(const  vector<int>& v, int  value);

void  removeDuplicates(vector<int>& v);

void vectorUnion(const vector<int>& v1, const vector<int>& v2, vector<int>& v3);
void vectorIntersection(const vector<int>& v1, const vector<int>& v2, vector<int>& v3);
