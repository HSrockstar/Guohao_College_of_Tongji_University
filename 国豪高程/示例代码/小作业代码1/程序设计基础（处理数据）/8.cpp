#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	unsigned int a = 0, b = 0;
	cin >> a >> b;
	double c = 2.0 * a * b / (a * 1.0 + b * 1.0);
	cout << c;
	return 0;
}