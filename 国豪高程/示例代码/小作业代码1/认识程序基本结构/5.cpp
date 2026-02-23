#include <iostream>
using namespace std;
double tempratureShift(int tempratureS) {
	double tempratureF = tempratureS * 1.8 + 32;
	return tempratureF;
}
int main()
{
	int tempratureS;
	cin >> tempratureS;
	double tempratureF = tempratureShift(tempratureS);
	cout << tempratureF << endl;
}