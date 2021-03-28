#include <vector>

using namespace std;

// exercise 4.7

void localMax(int** a, size_t size);
void randomArrayFill(int**& a, size_t x);
void showArray(int** a, size_t x);
bool clearNeighborhood(int**& a, size_t i, size_t j);

// exercise 4.8

void randomPluviosityYear(vector<vector<double>>& vec, int year);
double averagePluviosityDaily(const vector<vector<double>>& vec, int year);
double averagePluviosityMonth(const vector<vector<double>>& vec, int year, int month);
vector<string> maximumPluviosity(const vector<vector<double>>& vec, int year);
vector<string> aboveAverage(const vector<vector<double>>& vec, int year, double ave);
