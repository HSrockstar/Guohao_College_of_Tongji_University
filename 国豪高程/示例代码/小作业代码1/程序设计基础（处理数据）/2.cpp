#include <iostream>
using namespace std;
int main()
{
	int height = 0, weight = 0;
	cin >> height >> weight;
	double h2 = height / 100.0;
	double bmi = weight / (h2 * h2) + 0.00001;
	cout << bmi;
	return 0;
}