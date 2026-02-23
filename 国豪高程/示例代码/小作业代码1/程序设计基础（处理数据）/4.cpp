#include <iostream>
using namespace std;
int main()
{
	long long weight1 = 0, jin = 0, liang = 0, qian = 0;
	cin >> weight1;
	jin = weight1 / 500;
	liang = (weight1 - jin * 500) / 50;
	qian = (weight1 - jin * 500 - liang * 50) / 5;
	cout << jin << "½ï" << liang << "Á½" << qian << "Ç®";
	return 0;
}